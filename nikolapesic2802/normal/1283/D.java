import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.*; 
import java.util.StringTokenizer; 
import java.io.PrintWriter;
import java.io.*;
import java.util.stream.Collectors.*;
import java.lang.*;
import static java.util.stream.Collectors.*;
import static java.util.Map.Entry.*;
public class Ideo
{ 
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
   
static int power(int x,int y) 
{ 
    int res = 1;      // Initialize result 
  
      // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y%2==1) 
            res = (res*x); 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x);   
    } 
    return res; 
} 
 
 static int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
 
 
  static boolean compareSeq(char[] S, int x, int y, int n) 
    { 
        for (int i = 0; i < n; i++)
         {
 
            if (S[x] < S[y]) 
               return true;
            else if (S[x] > S[y]) 
                return false; 
            x = (x + 1) % n; 
            y = (y + 1) % n; 
        } 
        return true; 
    } 
 
    static void build(long[] sum,int[] arr,int n)
    {
      for(int i=0;i<(1<<n);i++)
      {
        long total=0;
        for(int j=0;j<n;j++)
        {
          if((i & (1 << j)) > 0)
            total+=arr[j];
        }
 
        sum[i]=total;
      }
    }
 
 
     static int count(long arr[], long x, int n) 
       {
 
        int l=0;
        int h=n-1;
 
        int res=-1;
        int mid=-1;
        while(l<=h)
        {
          mid=l+(h-l)/2;
          if(x==arr[mid])
          {
            res=mid;
            h=mid-1;
          }
          else if(x<arr[mid])
            h=mid-1;
          else
            l=mid+1;
        }
 
        if(res==-1)
          return 0;
 
        //res is first index and res1 is last index of an element in a sorted array total number of occurences is (res1-res+1)
 
        int res1=-1;
        l=0;
        h=n-1;
        while(l<=h)
        {
          mid=l+(h-l)/2;
          if(x==arr[mid])
          {
            res1=mid;
            l=mid+1;
          }
          else if(x<arr[mid])
            h=mid-1;
          else
            l=mid+1;
        }
 
 
 
        if(res1==-1)
          return 0;
        if(res!=-1 && res1!=-1)
          return (res1-res+1);
 
        return 0;
 
       } 
 
       static int parity(int a)
       {
    a^=a>>16;
    a^=a>>8;
    a^=a>>4;
    a^=a>>2;
    a^=a>>1;
    return a&1;
  }
/*
  PriorityQueue<aksh> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1.p < o2.p)
                return 1;
            else if (o1.p > o2.p)
                return -1;
            else
                return 0;
 
        });//decreasing order acc to p*/
static int power(int x, int y, int m)  
    { 
        if (y == 0) 
            return 1; 
          
        int p = power(x, y / 2, m) % m; 
        p = (p * p) % m; 
      
        if (y % 2 == 0) 
            return p; 
        else
            return (x * p) % m; 
    } 
static int modinv(int a, int m) 
    { 
        int g = gcd(a, m); 
        if (g != 1) 
            return 0;
        else 
        { 
           return power(a, m - 2, m); 
        } 
        //return 0;
    } 
 
static int[] product(int[] nums) {
    int[] result = new int[nums.length];
 
    int[] t1 = new int[nums.length];
    int[] t2 = new int[nums.length];
 
    t1[0]=1;
    t2[nums.length-1]=1;
 
    //scan from left to right
    for(int i=0; i<nums.length-1; i++){
        t1[i+1] = nums[i] * t1[i];
    }
 
    //scan from right to left
    for(int i=nums.length-1; i>0; i--){
        t2[i-1] = t2[i] * nums[i];
    }
 
    for(int i=0;i<nums.length;i++)
      {
        System.out.print(t1[i]+" "+t2[i]);
        System.out.println();
      }
 
    //multiply
    for(int i=0; i<nums.length; i++){
        result[i] = t1[i] * t2[i];
    }
 
    return result;
}
 
static int getsum(int[] bit,int ind)
{
  int sum=0;
  while(ind>0)
  {
    sum+=bit[ind];
    ind-= ind & (-ind);
  }
 
  return sum;
}
 
static void update(int[] bit,int max,int ind,int val)
{
  while(ind<=max)
  {
    bit[ind]+=val;
    ind+= ind & (-ind);
  }
}
 
    //static ArrayList<Integer>[] adj;
 
    static boolean check(long mid,long a,long b)
    {
      long count=1;
      while(count<=mid)
      {
        count++;
        if(a<b)
          a+=count;
        else
          b+=count;
 
        if(a==b)
          return true;
      }
        return false;
    }
 
    static class a1 implements Comparable<a1>
    {
      int p;
      int q;
 
      public a1(int p,int q)
      {
        this.p=p;
        this.q=q;
      }
 
      public int compareTo(a1 o)
      {
        return p-o.p;
      }
    }
    static int get(int arr[], int n) 
    { 
        int result = 0; 
        int x, sum; 
          
        // Iterate through every bit 
        for(int i=0; i<32; i++) 
        { 
            // Find sum of set bits at ith position in all  
            // array elements 
            sum = 0; 
            x = (1 << i); 
            for(int j=0; j<n; j++) 
            { 
                if((arr[j] & x)!=0) 
                sum++; 
            } 
            // The bits with sum not multiple of 3, are the 
            // bits of element with single occurrence. 
            if ((sum % 3)!=0) 
            result |= x; 
        } 
        return result; 
    } 
    /*        Collections.sort(orders, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                if (o1.diff < o2.diff) {
                    return -1;
                } else if (o1.diff > o2.diff) {
                    return 1;
                } else {
                    return 0;
                }
            }
        });  */
 
 
    static boolean isPrime(int n)  
    {  
        // Corner cases  
        if (n <= 1) return false;  
        if (n <= 3) return true;  
          
        // This is checked so that we can skip  
        // middle five numbers in below loop  
        if (n % 2 == 0 || n % 3 == 0) return false;  
          
        for (int i = 5; i * i <= n; i = i + 6)  
            if (n % i == 0 || n % (i + 2) == 0)  
            return false;  
          
        return true;  
    }  
      
    static int nextPrime(int N)  
    {  
      
        // Base case  
        if (N <= 1)  
            return (2-N);  
      
        int prime = N;  
        boolean found = false;  
      
        // Loop continuously until isPrime returns  
        // true for a number greater than n  
        while (!found)  
        {  
            if (isPrime(prime))  
                {
                  found = true;
                  break;
                }  
 
            prime++;
        }  
      
        return (prime-N);  
    }  
 
 
    static long product(long x) 
{ 
    long prod = 1; 
    while (x > 0)  
    { 
        prod *= (x % 10); 
        x /= 10; 
    } 
    return prod; 
} 
  
// This function returns the number having 
// maximum product of the digits 
static long findNumber(long l, long r) 
{ 
    // Converting both integers to strings 
    //string a = l.ToString(); 
    String b = Long.toString(r); 
  
    // Let the current answer be r 
    long ans = r; 
    for (int i = 0; i < b.length(); i++)  
    { 
        if (b.charAt(i) == '0') 
            continue; 
  
        // Stores the current number having 
        // current digit one less than current 
        // digit in b 
        char[] curr = b.toCharArray(); 
        curr[i] = (char)(((int)(curr[i] -  
                    (int)'0') - 1) + (int)('0')); 
  
        // Replace all following digits with 9 
        // to maximise the product 
        for (int j = i + 1; j < curr.length; j++) 
            curr[j] = '9'; 
  
        // Convert string to number 
        int num = 0; 
        for (int j = 0; j < curr.length; j++) 
            num = num * 10 + (curr[j] - '0'); 
  
        // Check if it lies in range and its product 
        // is greater than max product 
        if (num >= l && product(ans) < product(num)) 
            ans = num; 
    } 
  
    return product(ans); 
} 
 
static long mod=998244353;
 
static long pow(long in, long pow) {
    if(pow == 0) return 1;
    long out = pow(in, pow / 2);
    out = (out * out) % mod;
    if(pow % 2 == 1) out = (out * in) % mod;
    return out;
  }
  static long inv(long in) {
    return pow(in, mod - 2);
  }
 
  static void swap(int x,int y)
  {
    int temp=x;
    x=y;
    y=temp;
  }
 
  static int[] par;
  static int[] size;
  static int find(int i) 
  {
     if (par[i] == i)
      return i;
 
    return par[i] = find(par[par[i]]);
  }
 
  static void union(int x, int y) 
  {
      x = find(x);
      y = find(y);
      if (x == y)
        return;
      if (size[x] < size[y])
        swap(x, y);
 
      par[y] = x;
      size[x] += size[y];
    }


    static void multisourcebfs(long[] arr,int n,int m)
    {
      //TreeSet<Long> vis=new TreeSet<>();
      HashMap<Long,Long> dis=new HashMap<>();
      Queue<Long> q=new LinkedList<>();
 
      for(int i=0;i<arr.length;i++)
      {
        dis.put(arr[i],(long)0);
        q.add(arr[i]);
      }

      long[] res=new long[m];
      long ans=0;
      int k=0;
      while(!q.isEmpty())
      {
        if(k==m)
          break;
        long x=q.remove();
        if(dis.get(x)!=0)
        {
          ans+=dis.get(x);
          res[k]=x;
          k++;
        }

        if(dis.get(x-1)==null)
        {
          dis.put(x-1, dis.get(x)+1);
          q.add(x-1);
        }

        if(dis.get(x+1)==null)
        {
          dis.put(x+1, dis.get(x)+1);
          q.add(x+1);
        }
      }

      System.out.println(ans);

      for(int i=0;i<m;i++)
        System.out.print(res[i]+" ");
 
    }
 
    static final long INF = Long.MAX_VALUE/5;
    static ArrayList<Integer>[] adj;
    public static void main(String args[] ) throws Exception 
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
 
        FastReader sc=new FastReader();
        int n=sc.nextInt();
        int m=sc.nextInt();
        long[] x=new long[n];

        for(int i=0;i<n;i++)
          x[i]=sc.nextInt();

        multisourcebfs(x,n,m);
      }
 
    }