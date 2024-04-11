#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define INFLL 1000000000000000010ll
#define EPS 1e-7
#define UQ(x) (x).resize(distance((x).begin(),unique(all((x)))))
#define mid(x,y) (((x)+(y))>>1)

#define MAX_N 200100                         // second approach: O(n log n)
char T[MAX_N];                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

int Phi[MAX_N];                      // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                                              // and current suffix T+SA[i]

void countingSort(int k) {                                          // O(n)
  int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
  memset(c, 0, sizeof c);                          // clear frequency table
  for (i = 0; i < n; i++)       // count the frequency of each integer rank
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)                     // update the suffix array SA
    SA[i] = tempSA[i];
}

void constructSA() {         // this version can go up to 100000 characters
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
  for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
  for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
    countingSort(k);  // actually radix sort: sort based on the second item
    countingSort(0);          // then (stable) sort based on the first item
    tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
    for (i = 1; i < n; i++)                    // compare adjacent suffixes
      tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
      (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)                     // update the rank array RA
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
} }

void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;                                         // default value
  for (i = 1; i < n; i++)                            // compute Phi in O(n)
    Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
  for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
    while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
    PLCP[i] = L;
    L = max(L-1, 0);                             // L decreased max n times
  }
  for (i = 0; i < n; i++)                            // compute LCP in O(n)
    LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}
int tc;
set<ii> s;
vector<int> by[200005];
ll calc(int x) {
	if (x==0) return 0ll;
	return (ll)(x+1)*(ll)(x+1);
}
int main() {
	scanf("%d",&tc);
	while(tc--) {
		memset(T,0,sizeof(T));
		scanf("%s",T);
		n=strlen(T);
		T[n++]='$';
		s.clear();
		constructSA();
		computeLCP();

		ll ans=0ll;
		LCP[n]=0;
		for (int i=1;i<n;i++) {
			ans+=max(0,n-SA[i]-1-max(LCP[i],LCP[i+1]));
		}
		ll cur=calc(n-1);
		s.insert(mp(n-1,1));
		
		for (int i=0;i<=n;i++) by[i].clear();
		for (int i=1;i<n;i++) {
			by[LCP[i]].pb(i);
		}

		for (int l=0;l<=n;l++) {
			for (int x:by[l]) {
				set<ii>::iterator it=s.lower_bound(mp(x,-INF));
				if (it==s.end()) continue;
				int b=it->second,e=it->first;
				assert(b<=x && x<=e);
				s.erase(it);
				cur-=calc(e-b+1);
				if (b<x) s.insert(mp(x-1,b)),cur+=calc(x-b);
				if (e>x) s.insert(mp(e,x+1)),cur+=calc(e-x);
			}
			if (s.empty()) break;
			ans+=cur;
		}

		cout<<ans<<'\n';

	}
}