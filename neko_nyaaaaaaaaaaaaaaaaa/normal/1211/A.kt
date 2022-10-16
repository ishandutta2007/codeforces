import java.util.*

fun main() {
    val reader = Scanner(System.`in`)
    val n = reader.nextLine().toInt()
    
    var a = -1
    var b = -1
    var c = -1
    var aa = -1
    var bb = -1
    var cc = -1
    
    var i = 0
    repeat(n) {
        val x = reader.nextInt()
        i = i+1
        
        if (a == -1) {
            a = i
            aa = x
        } else if (b == -1) {
            if (x != aa) {
                b = i
                bb = x
            }
        } else if (c == -1) {
            if (x != aa && x != bb) {
                c = i
                cc = x
            }
        }
    }
    
    if (a == -1 || b == -1 || c == -1) {
        print("-1 -1 -1")
    } else {
    
    if (aa > bb) {
        var tmp1 = aa
        aa = bb
        bb = tmp1
        
        tmp1 = a
        a = b
        b = tmp1
    }
    
    if (bb > cc) {
        var tmp1 = cc
        cc = bb
        bb = tmp1
        
        tmp1 = c
        c = b
        b = tmp1    
    }
    
    if (aa > bb) {
        var tmp1 = aa
        aa = bb
        bb = tmp1
        
        tmp1 = a
        a = b
        b = tmp1
    }
    
    print(a)
    print(' ')
    print(b)
    print(' ')
    print(c)
    
    }
}