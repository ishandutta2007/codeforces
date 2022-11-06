import java.util.*;
import java.io.*;

public class Codeforces {
public static void main(String[] args) throws Exception {
Scanner s = new Scanner(System.in);
int n = s.nextInt();
 HashMap<String,String> hm = new HashMap<>();
 hm.put("red","Reality");
 hm.put("green","Time");
 hm.put("blue","Space");
 hm.put("purple","Power");
 hm.put("yellow","Mind");
 hm.put("orange","Soul");
 HashSet<String> hs = new HashSet<String>();
 hs.add("Reality");
hs.add("Time");
 hs.add("Space");
 hs.add("Power");
 hs.add("Mind");
 hs.add("Soul");
 while(n-->0) {
 String ss = s.next();
 if(hm.containsKey(ss)) hs.remove(hm.get(ss));
 }
 System.out.println(hs.size());
 for(String ss : hs)
 System.out.println(ss);
 }
}