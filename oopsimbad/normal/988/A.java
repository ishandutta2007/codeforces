import java.util.*;
import java.io.*;

public class RalIsDumb {
  public static void main(String[] args) throws Exception {
     Scanner s = new Scanner(System.in);
     HashSet<Integer> hs = new HashSet<Integer>();
    int n = s.nextInt();
    int k = s.nextInt();
    String out = "";
    for(int i = 1; i <= n; i++) {
       if(hs.add(s.nextInt()) && hs.size() <=k) out += i + " ";
    }
    if(hs.size() >= k) {
       System.out.println("YES");
       System.out.println(out);
    } else System.out.println("NO");
  }
}