import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val t = nextInt()
    repeat(t) {
        val n = nextInt()
        var k = nextInt()
        val g = MutableList(n) { mutableListOf<Int> () }
        repeat(n-1) {
            val x = nextInt() - 1
            val y = nextInt() - 1
            g[x].add(y)
            g[y].add(x)
        }

        val ans = mutableListOf<Int>()

        if (k == 1) {
            ans.add(1)
        } else {
            val par = IntArray(n)
            val que = mutableListOf(0)
            repeat(n) {
                val v = que[it]
                g[v].forEach { w ->
                    if (par[v] != w) {
                        par[w] = v
                        que.add(w)
                    }
                }
            }

			var leaf = 0
			val deg = IntArray(n)
            repeat(n) {
				deg[it] = g[it].size
                if (g[it].size == 1) leaf++
            }

            if (leaf < k) {
                // no
            } else {
                val ban = IntArray(n)
                for (i in n - 1 downTo 0) {
                    if (leaf > k) {
                        val v = que[i]
                        leaf--
                        ban[v] = 1
                        deg[par[v]]--
                        if (deg[par[v]] == 1) {
                            leaf++
                        }
                    }
                }
                repeat(n) {
                    if (ban[it] == 0) ans.add(it+1)
                }
            }
		}

		if (ans.isEmpty()) {
			println("No")
		} else {
			println("Yes")
			println(ans.size)
			println(ans.joinToString(" "))
		}
    }
}