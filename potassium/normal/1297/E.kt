import java.util.*
 
fun main() {
    val t = readLine()!!.toInt();
    
    for (i in 0 until t) {
        var (n,k) = readLine()!!.split(" ").map { it.toInt() };
        
        var graph =  Array< ArrayList<Int> >(n+1) { ArrayList<Int>() };
        
        for (j in 0 until n-1) {
            var (u,v) = readLine()!!.split(" ").map { it.toInt() };
            graph[u].add(v);
            graph[v].add(u);
        }
        
        var Leaf = ArrayList<Int>();
        var isLeaf = Array<Boolean>(n+1) {false};
        var deg = Array<Int>(n+1) {0};
        
        for (j in 1..n) {
            deg[j] = graph[j].size;
            if (graph[j].size == 1) {
                Leaf.add(j);
                isLeaf[j] = true;
            }
        }
                
        while (Leaf.size > k) {
            var node = Leaf[Leaf.size - 1];
            Leaf.removeAt(Leaf.size - 1);
            
            for (adj in graph[node])
                if (!isLeaf[adj]) {
                    deg[adj]--;
                    if (deg[adj] == 1) {
                        Leaf.add(adj);
                        isLeaf[adj] = true;
                    }
                }
        }
        
        if (Leaf.size < k) {
            println("No");
        } else {
            println("Yes");
            
            var ans = ArrayList<Int>();
            for (j in Leaf)
                ans.add(j);
                
            for (j in 1..n)
                if (!isLeaf[j])
                    ans.add(j);
                    
            println(ans.size);
            for (node in ans)
                print("${node} ");
            println();
        }
    }
}