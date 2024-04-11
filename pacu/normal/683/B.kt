class Person(height: Int, name: String) {
    var height = height
    var name = name
}

fun main(args: Array<String>){
    var n = Integer.parseInt(readLine())
    val list: MutableList<Person> = arrayListOf()
    var i = 0
    while(i<n)
    {
        var (x, y) = readLine()!!.split(' ')
        var h = Integer.parseInt(y)
        list.add(Person(h,x))
        i++
    }
    val clist: List<Person> = list
    val sortedList = clist.sortedBy{it.height}
    i = 0
    while(i<n)
    {
        println(sortedList[i].name)
        i++
    }
}