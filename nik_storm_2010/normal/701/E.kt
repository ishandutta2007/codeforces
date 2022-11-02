//package ru.spbau.mit

import java.io.*
import java.util.*

data class Treelandia(val nodes: List<Node>, val universityPairs: Int) {
    val nodeCount: Int
        get() = nodes.size
}

data class Node(
    val index: Int,
    val hasUniversity: Boolean,
    val edges: MutableList<Node> = mutableListOf()
)

fun readTreelandia(scanner: Scanner): Treelandia {
    val nodeCount = scanner.nextInt()
    val universityPairs = scanner.nextInt()
    val hasUniversityIndexes = BooleanArray(nodeCount)
    repeat(2 * universityPairs) {
        val universityIndex = scanner.nextInt() - 1
        hasUniversityIndexes[universityIndex] = true
    }
    val nodes = (0 until nodeCount).map { Node(it, hasUniversityIndexes[it]) }
    repeat(nodeCount - 1) {
        val edgeA = scanner.nextInt() - 1
        val edgeB = scanner.nextInt() - 1
        nodes[edgeA].edges.add(nodes[edgeB])
        nodes[edgeB].edges.add(nodes[edgeA])
    }
    return Treelandia(nodes, universityPairs)
}

fun computeSubtreeUniversities(subtreeUniversities: IntArray, node: Node, parent: Node = node) {
    subtreeUniversities[node.index] = (if (node.hasUniversity) 1 else 0) +
        node.edges
            .filter { it !== parent }
            .map {
                computeSubtreeUniversities(subtreeUniversities, it, node)
                subtreeUniversities[it.index]
            }
            .sum()
}

fun findOptimalNode(
    subtreeUniversities: IntArray,
    universityPairs: Int,
    node: Node,
    parent: Node = node
): Node {
    val maxSubtreeChild = node.edges
        .filter { it != parent }
        .map { it to subtreeUniversities[it.index] }
        .maxBy { it.second }!!
    return if (maxSubtreeChild.second <= universityPairs) node else {
        findOptimalNode(subtreeUniversities, universityPairs, maxSubtreeChild.first, node)
    }
}

fun findDistancesToUniversities(node: Node, parent: Node = node, distanceToRoot: Long = 0L): Long {
    return (if (node.hasUniversity) distanceToRoot else 0L) +
        node.edges
            .filter { it !== parent }
            .map { findDistancesToUniversities(it, node, distanceToRoot + 1L) }
            .sum()
}

fun findMinDistancesSum(treelandia: Treelandia): Long {
    val subtreeUniversities = IntArray(treelandia.nodeCount)
    computeSubtreeUniversities(subtreeUniversities, treelandia.nodes[0])
    val optimalNode =
        findOptimalNode(subtreeUniversities, treelandia.universityPairs, treelandia.nodes[0])
    return findDistancesToUniversities(optimalNode)
}

fun main(args: Array<String>) {
    val scanner = Scanner(BufferedInputStream(System.`in`, 32768))
    val minDistancesSum = findMinDistancesSum(readTreelandia(scanner))
    println(minDistancesSum)
}