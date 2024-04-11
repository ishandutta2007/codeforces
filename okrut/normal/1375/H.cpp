#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int K = 1<<6;
const int N = 1<<12;
const int S = 1<<8;
const int Q = 1<<16;
const int M = 2.2e6;

int Arr[N], Pos[N], No[N][N][2], no;
int Mini[N/S][N+N], Maks[N/S][N+N], Ans[Q];
pair <int, int> Out[M];

int read (int *T, int l, int r, int ret, int (*best)(int, int))
{
	l+=N;
	r+=N;
	while (l<r)
	{
		ret = best(ret, T[l]);
		ret = best(ret, T[r]);
		l = (l+1)/2;
		r = (r-1)/2;
		
	}
	if (l==r) ret = best(ret, T[l]);
	return ret;
}

void calc (int l, int r, int cnt)
{
	if (l==r) 
	{
		No[l][r][cnt] = Pos[l];
		debug ("\nSolve for [%d %d]\n", l, r);
		debug ("For [%d %d]: %d\n", Pos[l], Pos[r], No[l][r][cnt]);
		return;
	}
	
	int mid = (l+r)/2;
	calc(l, mid, cnt^1);
	calc(mid+1, r, cnt^1);
	
	vector <int> P;
	rep(i,l,r+1) P.pb(Pos[i]);
	sort(P.begin(), P.end());
	
	debug ("\nSolve for [%d %d]\n", l, r);
	
	for (auto a=P.begin(); a!=P.end(); a++)
	{
		int lb = -1, le = -1, ub = -1, ue = -1;
		
		for (auto b=a; b!=P.end(); b++)
		{
			if (Arr[*b]> mid)
			{
				if (ub==-1) ub = Arr[*b];
				ue = Arr[*b];
			}
			else
			{
				if (lb==-1) lb = Arr[*b];
				le = Arr[*b];
			}
			
			int aa = Arr[*a];
			int ab = Arr[*b];
			
			if (le==-1) No[aa][ab][cnt] = No[ub][ue][cnt^1];
			else if (ue==-1) No[aa][ab][cnt] = No[lb][le][cnt^1];
			else
			{
				Out[no] = {No[lb][le][cnt^1], No[ub][ue][cnt^1]};
				debug ("Out[%d] = %d %d\n", no, No[lb][le][cnt^1], No[ub][ue][cnt^1]);
				No[aa][ab][cnt] = no++;
			}
			
			debug ("For %d %d: %d\n", *a, *b, No[aa][ab][cnt]);
		}
		
	}
}

int mini (int a, int b) {return min(a,b);};
int maks (int a, int b) {return max(a,b);};

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	rep(j,0,N/S) rep(i,0,N+N) 
	{
		Mini[j][i] = N;
		Maks[j][i] = -1;
	}
	
	int n,q ;
	scanf ("%d %d", &n, &q);
	rep(i,0,n) 
	{
		scanf ("%d", &Arr[i]);
		Arr[i]--;
		Pos[Arr[i]] = i;
	}
	no = n;
	
	for (int l = 0; l<n; l+=S)
	{
		int r = min(n, l+S)-1;
		
		calc(l, r, 0);
	}
	
	debug ("Calculated\n");
	
	
	rep(i,0,n)
	{
		int b = Arr[i]/S;
		Mini[b][N+i] = Maks[b][N+i] = i;
	}
	
	rep(b,0,N/S)
	{
		for (int i=N-1; i>0; i--) 
		{
			Mini[b][i] = min(Mini[b][i*2], Mini[b][i*2+1]);
			Maks[b][i] = max(Maks[b][i*2], Maks[b][i*2+1]);
		}
	}
	
	
	debug ("Trees initialized - %d - %d \n", Mini[0][1], Maks[0][1]);
	
	rep(w,0,q)
	{
		int l, r;
		scanf ("%d %d", &l, &r);
		l--; r--;
		
		int last = -1;
		
		debug ("\nProcess [%d %d]\n", l, r);
		
		rep(i,0,N/S)
		{
			int b = read(Mini[i], l, r, N, &mini);
			int e = read(Maks[i], l, r, 0, &maks);
			
			debug ("For block %d found %d %d\n",i, b, e);
			
			if (b==N) continue;
			
			b = Arr[b];
			e = Arr[e];
			
			if (last==-1) last = No[b][e][0];
			else
			{
				Out[no] = {last, No[b][e][0]};
				last = no++;
			}
		}
		Ans[w] = last;
	}
	
	printf ("%d\n", no);
	rep(i,n,no) printf ("%d %d\n", Out[i].fi+1, Out[i].se+1);
	rep(i,0,q) printf ("%d ", Ans[i]+1);
	printf ("\n");
	
}