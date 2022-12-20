fun main(args: Array<String>) {
    var input: String = readLine()!!
    var l: MutableList<Char> = arrayListOf()
    var i = 0
    while(i < input.length)
    {
        if(input[i]==' ')
        {
            if(l.size > 0 && l[l.size-1] != ' ' && l[l.size-1] != ',' && l[l.size-1] != '.' && i < input.length-1)
                l.add(input[i])
        }
        else if(input[i]==',' || input[i]=='.')
        {
            if(l[l.size-1]==' ') l.removeAt(l.size-1)
            l.add(input[i])
        }
        else if('a' <= input[i] && input[i] <= 'z')
        {
            if(l.size>0 && (l[l.size-1]==',' || l[l.size-1]=='.'))
                l.add(' ')
            if(l.size==0 || (l.size>1 && l[l.size-2]=='.'))
                l.add(input[i].toUpperCase())
            else
                l.add(input[i])
        }
        else
        {
            if(l.size>0 && (l[l.size-1]==',' || l[l.size-1]=='.'))
                l.add(' ')
            if(l.size==0 || (l.size>1 && l[l.size-2]=='.'))
                l.add(input[i])
            else
                l.add(input[i].toLowerCase())
        }
        i++
    }
    i = 0
    while(i < l.size)
    {
        if(i<l.size-1 || l[i]!=' ')
            print(l[i])
        i++
    }
    println()
}