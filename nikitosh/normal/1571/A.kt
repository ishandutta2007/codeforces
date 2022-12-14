import kotlin.math.min
import kotlin.math.max
import java.io.*
import java.util.*
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    repeat(readInt()) {
        var s = readLine()!!
        if (s.indexOf('>') != -1 && s.indexOf('<') != -1) 
            println('?')
        else {
            if (s.indexOf('>') != -1)
                println('>')
            else {
                if (s.indexOf('<') != -1)
                    println('<')
                else
                    println('=')
            }
        }
    }

}