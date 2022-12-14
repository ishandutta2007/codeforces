/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

#define MX 100005

// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm
// Refer to "Suffix arrays: A new method for on-line string searches",
// by Udi Manber and Gene Myers

//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!

//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// sf_rank = The inverse of the suffix array. sf_rank[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> sf_rank[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if sf_rank[i] < sf_rank[j]

int str[MX]; //input
int sf_rank[MX], pos[MX]; //output
int cnt[MX], nxt[MX]; //internal
bool bh[MX], b2h[MX];

// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}

void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);
  //{pos contains the list of suffixes sorted by their first character}

  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }

  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      nxt[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing strings starting with the same h characters}

    for (int i = 0; i < n; i = nxt[i]){
      cnt[i] = 0;
      for (int j = i; j < nxt[i]; ++j){
        sf_rank[pos[j]] = i;
      }
    }

    cnt[sf_rank[n - h]]++;
    b2h[sf_rank[n - h]] = true;
    for (int i = 0; i < n; i = nxt[i]){
      for (int j = i; j < nxt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = sf_rank[s];
          sf_rank[s] = head + cnt[head]++;
          b2h[sf_rank[s]] = true;
        }
      }
      for (int j = i; j < nxt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[sf_rank[s]]){
          for (int k = sf_rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[sf_rank[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    sf_rank[pos[i]] = i;
  }
}
// End of suffix array algorithm


// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
int height[MX];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n){
  for (int i=0; i<n; ++i) sf_rank[pos[i]] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (sf_rank[i] > 0){
      int j = pos[sf_rank[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      height[sf_rank[i]] = h;
      if (h > 0) h--;
    }
  }
}

#define LOG2_LEN 16

int RMQ[MX][LOG2_LEN + 1];

void init_rmq(int N){
    for(int i = 0;i < N;++i) RMQ[i][0] = height[i];

    for(int j = 1;(1 << j) <= N;++j){
        for(int i = 0;i + (1 << j) - 1 < N;++i){
            if(RMQ[i][j-1] <= RMQ[i + (1 << (j-1))][j-1])
                RMQ[i][j] = RMQ[i][j-1];
            else
                RMQ[i][j] = RMQ[i + (1 << (j-1))][j-1];
        }
    }
}

// lcp(pos[x],pos[y])
int lcp(int x, int y, int N){
    if(x == y) return N - pos[x];
    if(x > y) swap(x,y);

    int log = 0;
    while((1 << log) <= (y-x)) ++log;
    --log;

    return min(RMQ[x+1][log],RMQ[y-(1<<log)+1][log]);
}

// End of longest common prefixes algorithm

int ar[100001];
vector < pair < int, int > > out;

int find_left(int l, int r, int v){
    int r1 = r;
    int mid = (l + r) / 2;
    while(l < mid){
        if(ar[mid] < v) l = mid + 1;
        else r = mid;
        mid = (l + r) / 2;
    }
    if(mid < r1 && ar[mid] < v)mid++;
    return mid;
}

int find_right(int l, int r, int v){
    int r1 = r;
    int mid = (l + r) / 2;
    while(l < mid){
        if(ar[mid] >= v)l = mid;
        else r = mid - 1;
        mid = (l + r) / 2;
    }
    if(mid < r1 && ar[mid + 1] >= v) mid++;
    return mid;
}


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    string s; cin >> s;
    int N = s.size();
    REP(i, N) str[i] = s[i] - 'A';

    suffixSort(N);
    getHeight(N);
    init_rmq(N);
    REP(i, N) ar[i] = lcp(i, sf_rank[0], N);

    h = sf_rank[0];


    for(int i = 0; i < N; i++){
        if(ar[i] != (N - pos[i])) continue;
        e = find_left(0, min(h, (LL)i), ar[i]);
        d = find_right(max(h, (LL)i), N - 1, ar[i]);
        out.pb(mp(N - pos[i], d - e + 1));
    }
    vsort(out);

    cout << out.size() << endl;
    REP(i, out.size()) cout << out[i].xx << " " << out[i].yy << endl;

}
/*
AAAAAAAAAAAAAAAAXAAAAAAAAAAAAAAAAAAAAAAA
*/