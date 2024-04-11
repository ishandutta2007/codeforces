import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author: pashka
 */
public class SuffixAutomaton {

    class Node {
        Node[] jumps = new Node[256];
        Node suffixLink;
//        String s;
        int len;
        boolean z;
        int c1, c2;
    }

    private List<Node> buildAutomaton(String s) {
        List<Node> result = new ArrayList<Node>();
        Node root = new Node();
//        root.s = "";
        result.add(root);
        Node last = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            Node newNode = new Node();
            newNode.len = i + 1;
            Node cur = last;
//            newNode.s = cur.s + c;
            result.add(newNode);
            cur.jumps[c] = newNode;
            cur = cur.suffixLink;
            while (true) {
                if (cur == null) {
                    newNode.suffixLink = root;
                    break;
                } else if (cur.jumps[c] == null) {
                    cur.jumps[c] = newNode;
                    cur = cur.suffixLink;
                } else if (cur.jumps[c].len == cur.len + 1) {
                    newNode.suffixLink = cur.jumps[c];
                    break;
                } else {
                    Node old = cur.jumps[c];
                    Node copy = new Node();
                    copy.len = cur.len + 1;
//                    copy.s = cur.s + c;
                    copy.jumps = old.jumps.clone();
                    old.suffixLink = copy;
                    newNode.suffixLink = copy;
                    Node node = cur;
                    while (node != null && node.jumps[c] == old) {
                        node.jumps[c] = copy;
                        node = node.suffixLink;
                    }
                    copy.suffixLink = node == null ? root : node.jumps[c];
                    result.add(copy);
                    break;
                }
            }
            last = newNode;
        }
        return result;
    }

    public static void main(String[] args) {
        new SuffixAutomaton().run();
    }

    private void run() {
//        List<Node> a = buildAutomaton("apple$");
//        dfs(a.get(0));
//        for (Node node : a) {
//            System.out.println(node.s + " " + node.c1);
//            for (int c = 0; c < 256; c++) {
//                if (node.jumps[c] != null) {
//                    System.out.println(" " + ((char)c) + " " + node.jumps[c].s);
//                }
//            }
//        }

        Scanner in = new Scanner(System.in);
        String s1 = in.nextLine();
        String s2 = in.nextLine();
        List<Node> automaton = buildAutomaton(s1 + "$" + s2 + "#");
        dfs(automaton.get(0));
        int res = -1;
        for (Node node : automaton) {
//            System.out.println(node.s + " " + node.c1 + " " + node.c2);
            if (node.c1 == 1 && node.c2 == 1) {
                int len = node.suffixLink.len + 1;
                if (res == -1 || res > len) {
                    res = len;
                }
            }
        }
        System.out.println(res);
    }

    private void dfs(Node node) {
        if (node.z) return;
        node.z = true;
        for (int c = 0; c < 256; c++) {
            if (node.jumps[c] != null) {
                if (c == '$')
                    node.c1++;
                else if (c == '#')
                    node.c2++;
                else {
                    dfs(node.jumps[c]);
                    node.c1 += node.jumps[c].c1;
                    node.c2 += node.jumps[c].c2;
                }
            }
        }
    }

}