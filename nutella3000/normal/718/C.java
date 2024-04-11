
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static final long Mod=(long) (1e9+7);
    public static long[][] fib=new long[2][2];
    public static long[][] temp=new long[2][2];
    public static long[][] change=new long[2][2];

    public static void mul(long[][] res,long[][] A,long[][] B){
        res[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%Mod;
        res[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%Mod;
        res[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%Mod;
        res[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%Mod;
    }

    public static void add(long[][] res,long[][] A,long[][] B){
        res[0][0]=(A[0][0]+B[0][0])%Mod;
        res[0][1]=(A[0][1]+B[0][1])%Mod;
        res[1][0]=(A[1][0]+B[1][0])%Mod;
        res[1][1]=(A[1][1]+B[1][1])%Mod;
    }

    public static void quickPow(long[][] res,long[][] A,long y) {
        res[0][0]=res[1][1]=1;
        res[0][1]=res[1][0]=0;
        A[0][0]=A[0][1]=A[1][0]=1;
        A[1][1]=0;

        while(y>0) {
            if((y&1)==1) {
                mul(temp,res,A);
                copy(res,temp);
            }
            mul(temp,A,A);
            copy(A,temp);
            y>>=1;
        }
    }

    public static void copy(long[][] A,long[][] B) {
        A[0][0]=B[0][0];
        A[0][1]=B[0][1];
        A[1][0]=B[1][0];
        A[1][1]=B[1][1];
    }

    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader sc = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, sc, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader sc, PrintWriter out) throws IOException {
            int n=sc.nextInt();
            int m=sc.nextInt();
            long[] a=new long[n+1];

            for(int i=1;i<=n;i++)
                a[i]=sc.nextLong();
            SegTree sgt=new SegTree(n,a);
            sgt.build(1, 1, n);
            StringBuilder ans=new StringBuilder();
            while(m-->0) {
                int opt=sc.nextInt();
                int l=sc.nextInt();
                int r=sc.nextInt();
                if(opt==1) {
                    long val=sc.nextLong();
                    quickPow(change,fib,val);
                    sgt.change(1, l, r, change);
                }
                else {
                    //	out.println(sgt.ask(1, l, r));
                    ans.append(sgt.ask(1, l, r)+"\n");
                }
            }
            out.print(ans);
        }
    }

    static class SegTree{
        class Node{
            int l;
            int r;
            long[][] matrix;
            long sum;
            long[][] tag;

            public Node(int l,int r) {
                this.l=l;
                this.r=r;
                this.tag=new long[2][2];
                this.matrix=new long[2][2];
            }
        }
        public Node[] t;
        public long[] buf;

        public SegTree(int n,long[] buf) {
            this.t=new Node[(n+10)<<2];
            this.buf=buf;
        }

        public boolean jud(long[][] A) {
            return A[0][0]==1&&A[0][1]==0&&A[1][0]==0&&A[1][1]==1;
        }

        public void init(long[][] A) {
            A[0][0]=A[1][1]=1;
            A[0][1]=A[1][0]=0;
        }

        public void pushUp(int p) {
            add(temp,t[p*2].matrix,t[p*2+1].matrix);
            copy(t[p].matrix,temp);
            t[p].sum=(t[p].matrix[1][0]+t[p].matrix[1][1])%Mod;
        }

        public void pushDown(int p) {
            if(!jud(t[p].tag)) {
                mul(temp,t[p*2].tag,t[p].tag);
                copy(t[p*2].tag,temp);
                mul(temp,t[p*2+1].tag,t[p].tag);
                copy(t[p*2+1].tag,temp);
                mul(temp,t[p*2].matrix,t[p].tag);
                copy(t[p*2].matrix,temp);
                mul(temp,t[p*2+1].matrix,t[p].tag);
                copy(t[p*2+1].matrix,temp);
                t[p*2].sum=(t[p*2].matrix[1][0]+t[p*2].matrix[1][1])%Mod;
                t[p*2+1].sum=(t[p*2+1].matrix[1][0]+t[p*2+1].matrix[1][1])%Mod;
                init(t[p].tag);
            }
        }

        public void build(int p,int l,int r) {
            t[p]=new Node(l,r);
            init(t[p].tag);
            if(l==r) {
                quickPow(change,fib,buf[l]-1);
                copy(t[p].matrix,change);
                t[p].sum=(t[p].matrix[1][0]+t[p].matrix[1][1])%Mod;
                return ;
            }
            int mid=(l+r)>>1;
            build(p*2,l,mid);
            build(p*2+1,mid+1,r);
            pushUp(p);
        }

        public void change(int p,int l,int r,long[][] val) {
            if(t[p].l>=l&&t[p].r<=r) {
                mul(temp,t[p].matrix,val);
                copy(t[p].matrix,temp);
                t[p].sum=(t[p].matrix[1][0]+t[p].matrix[1][1])%Mod;
                mul(temp,t[p].tag,val);
                copy(t[p].tag,temp);
                return ;
            }
            pushDown(p);
            int mid=(t[p].l+t[p].r)>>1;
            if(l<=mid)
                change(p*2,l,r,val);
            if(r>mid)
                change(p*2+1,l,r,val);
            pushUp(p);
        }

        public long ask(int p,int l,int r) {
            if(t[p].l>=l&&t[p].r<=r)
                return t[p].sum;
            pushDown(p);
            int mid=(t[p].l+t[p].r)>>1;
            long res=0;
            if(l<=mid)
                res+=ask(p*2,l,r);
            if(r>mid)
                res+=ask(p*2+1,l,r);
            return res%Mod;
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768*10);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public boolean hasNext() {
            try {
                String string = reader.readLine();
                if (string == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(string);
                return tokenizer.hasMoreTokens();
            } catch (IOException e) {
                return false;
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public BigInteger nextBigInteger() {
            return new BigInteger(next());
        }

    }
}