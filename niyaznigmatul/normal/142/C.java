import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static String[] answers = {".",
"..",
"...",
"....",
".....",
"......",
".......",
"........",
".........",
"..",
"....",
"......",
"........",
"..........",
"............",
"..............",
"................",
"..................",
"...",
"......",
"AAA.A..A.",
".AAA..A...A.",
"AAA.B.ABBB.A..B",
".AAA.B..ABBB..A..B",
"AAABCCC.A.B.C..ABBBC.",
".AAABCCC..A.B.C...ABBBC.",
"AAABCCC.D.A.B.CDDD.ABBBC..D",
"....",
"........",
"...AAA.A..A.",
".AAA.BA..BA.BBB.",
".....AAA.B.ABBB.A..B",
"...AAABBBCA..B.CA..BCCC.",
".AAABBB.CA.DB..CA.DB.CCCDDD.",
".....AAA.BCCCDA..B.C.DA.BBBCDDD.",
"...AAABBBCCCDA.EB..C.DA.EB..CDDDEEE.",
".....",
"..........",
"AAA.A..ABBBB..B",
".....AAA.BA..BA.BBB.",
"AAA.B.ABBBCA.DBCCCD.C.DDD",
"...AAA.BBBA..CB.AD.CBDDDCCC..D",
"..AAA.BCCCABBB.CDA.EB.CDDDE...D.EEE",
"...AAA.B.CCCABBB.DCEA.FB.DCEEEF.DDDE.FFF",
".AAAB.CCC..ADBBBC..EADBF.CG.EDDDFGGGEEE.FFF.G",
"......",
"............",
"...AAA.A..ABBBB..B",
".AAA..A...ABCBBBCCCBC...",
".....AAA.B.ABBBCA.DBCCCD.C.DDD",
"...AAABBBCA..B.CA.DBCCCEDDDEEED....E",
"....AAABBB.CA..BCCCA.DB.EC.FDDDEFFFD.EEE.F",
".......AB.CCCAAABBBCDDDABE.CFDG..EFFFDG.EEE.FGGG",
".....ABBBC.DDDA.B.CCCDAAABECF.DGHEEE.FGGGHHHEFFF.GH...",
".......",
"..............",
"AAA.A..ABBBB.CB.C.CCC",
".AAA.BA..BA.BBBCDCCCDDDCD...",
"..AAA...A.BBBAC.BCCCDB.ECDDDE.D.EEE",
"...AAABBB.A..BC.AD.BCDDDECCCFDEEE.F.E..FFF",
"AAA.BBB.ACCCB..ADCEB.DDDCEEEF.DGE.HFFFGHHHF.GGG.H",
".AAA.BBB.CADDDB..CA.DEB.CCCFDEEEGFFFHE.IGGGFHIIIG..HHH.I",
"..AAA.BBBCCCADDDB..C.AEDFB.GCEEEDFFFGGGHEIF.JGHHH.IJJJ...HIII.J",
"........",
"................",
"...AAA.A..ABBBB.CB.C.CCC",
".....AAA.BA..BA.BBBCDCCCDDDCD...",
"..AAABBBA..B.A.CBDDDCCCD.CE.DF.EFFFEEE.F",
"...AAA.BBBA..CB.AD.CBDDDCCCE.DFEEEG.FFFEG.F..GGG",
"...ABBBCAAADB.CCCADB.CE.DDDF.EEEFFFGEHHHIFGGGH.I.G..HIII",
"...AAA.B.CCCABBB.DCEA.FB.DCEEEF.DDDEGFFFHHHIGGGJ.H.IGJJJ.HIII..J",
"...ABBB.CDAAAEBCCCDDDAEBF.CD.GEEEFFFGGGHHHF.IJ.GKHLIIIJJJKHLLLIJ.KKKL...",
".........",
"..................",
"AAA.A..ABBBBC.BCCCC.DDDD..D",
".AAA..A...ABCBBBCCCBCDDD.ED..ED.EEE.",
"..AAABBBA..B.ACDBCCCDDDECDEEE.FFFEG.FGGG.F..G",
"...AAA.BBBA..CB.AD.CBDDDCCCE.DFFFEEE.FGE.H.FGHHH.GGG.H",
"..AAA.BCCCABBB.C.AD.B.C.EDDDFEEED.GFFFEGGGFHIIIJG.H.I.J.HHHIJJJ",
".AAABCCC.DA.B.C..DABBBCEDDDFGEEEHFFFGGGEHHHFGIIIHJKKKLI..J.K.LI.JJJKLLL.",
"....AAA.BC.DDDABBBCCCDEA.FBC.GDEFFF.GGGEEEHF.I.GJJJHHHIIIKJLH.MIKKKJLMMM...KLLL.M",
};
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        char[][][][] answer = new char[10][10][][];
        for (int n = 1, cur = 0; n <= 9; n++) {
            for (int m = 1; m <= 9; m++, cur++) {
                String s = answers[cur];
                answer[n][m] = new char[n][m];
                for (int i = 0; i < n; i++) {
                    answer[n][m][i] = s.substring(0, m).toCharArray();
                    s = s.substring(m);
                }
            }
        }
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] output = answer[n][m];
        int ans = 0;
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < m; j++) {
                if (output[i][j] != '.') {
                    ans = Math.max(ans, output[i][j] - 'A' + 1);
                }
            }
        }
        out.println(ans);
        for (char[] e : output) {
            out.println(e);
        }
    }


    }

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    IOException happened;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                st = new StringTokenizer(line);
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }