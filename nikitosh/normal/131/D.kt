import java.io.InputStream
import java.util.*

class Vertex {
    val neighbours: MutableList<Vertex> = mutableListOf()

    fun addNeighbour(vertex: Vertex) {
        neighbours.add(vertex)
    }
}

class Graph(val vertices: List<Vertex>) {
    companion object {
        fun read(inputStream: InputStream): Graph {
            val input = Scanner(inputStream)
            val vertexNumber = input.nextInt()
            val vertices = List(vertexNumber, { _ -> Vertex() })
            val graph = Graph(vertices)
            for (i in 1..vertexNumber) {
                val vertexV = input.nextInt()
                val vertexU = input.nextInt()
                graph.addUndirectedEdge(vertices[vertexV - 1], vertices[vertexU - 1])
            }
            return graph
        }
    }

    internal fun addUndirectedEdge(v: Vertex, u: Vertex) {
        v.addNeighbour(u)
        u.addNeighbour(v)
    }

    fun findCycle(): Set<Vertex> {
        val visitedVertices = HashSet<Vertex>()
        val path = ArrayDeque<Vertex>()
        fun findCycle(vertex: Vertex, previousVertex: Vertex): Set<Vertex>? {
            visitedVertices.add(vertex)
            path.add(vertex)
            vertex.neighbours.forEach { neighbour ->
                if (neighbour in visitedVertices && neighbour != previousVertex) {
                    return path.drop(path.indexOf(neighbour)).toSet()
                }
                if (!visitedVertices.contains(neighbour)) {
                    findCycle(neighbour, vertex)?.let { return it }
                }
            }
            path.removeLast()
            return null
        }
        return findCycle(vertices[0], vertices[0])!!
    }

    fun getDistanceToCycle(vertex: Vertex, previousVertex: Vertex, cycleVertices: Set<Vertex>): Int? {
        if (cycleVertices.contains(vertex)) {
            return 0
        }
        vertex.neighbours.forEach({ neighbour ->
            if (neighbour != previousVertex) {
                getDistanceToCycle(neighbour, vertex, cycleVertices)?.let { return it + 1 }
            }
        })
        return null
    }
}

fun solve(graph: Graph): List<Int> {
    val cycleVertices = graph.findCycle()
    return graph.vertices.map({ vertex -> graph.getDistanceToCycle(vertex, vertex, cycleVertices)!! }).toList()
}

fun main(args: Array<String>) {
    val graph = Graph.read(System.`in`)
    println(solve(graph).joinToString(separator = " "))
}