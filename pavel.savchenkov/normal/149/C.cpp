#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

struct p
{
       int a,ind;
       p(int _a = 0,int _ind = 0) {a = _a; ind = _ind; };
       friend bool operator <(const p &x, const p &y) { return  (x.a > y.a); };
};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n; scanf("%d",&n);
    p d[n];
    for (int i=0; i<n; i++) { int c; scanf("%d",&c); d[i] = p(c,i+1); }
    sort(d,d+n);
    vector <p> t[2];
    int s[2]; s[0] = s[1] = 0;

    for (int i=0; i<n; i++)
    {
     if (s[0] < s[1]) { t[0].pb(d[i]); s[0]+=d[i].a; }
      else  { t[1].pb(d[i]); s[1]+=d[i].a; }
    }
    
	for (int j=0; j<2; j++)
		sort(t[j].begin(),t[j].end());
	int m;
	if ((int)t[0].size() > (int)t[1].size()) m = 0; else m = 1;

	while ((int)t[m].size() - (int)t[1-m].size() > 1)
	{
		t[1-m].pb(*(t[m].end()-1));
		t[m].pop_back();
	}
	
    for (int j=0; j<2; j++)
    {
     printf("%d\n",(int)t[j].size());
     for (int i=0; i<(int)t[j].size();i++)
      printf("%d ",t[j][i].ind);
     puts("");
    }
    
    return 0;
}