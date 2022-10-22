private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>){
    val fking_useless_piece_of_sheet = readInt()
    val name = readLine()
    var ls: List<String> = listOf()
    var counter = 0
    var ko = 0
    for (i in 2 until name!!.length){
        if ((name[i] == 'x') and (name[i-1]=='x') and (name[i-2]=='x') and (ko==0)){

            counter++
        }
    }
    print(counter)
}