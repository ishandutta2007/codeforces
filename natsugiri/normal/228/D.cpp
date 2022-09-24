#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;

template<class T>
struct Fenwick {
    int n;
  vector<T> data;
  Fenwick() {}
    Fenwick(int n) : n(n) {
	  data=vector<T>(n, 0);
    }
    
    void add(int p, T v) {
        for (; p<n; p|=p+1) data[p]+=v;
    }

    T sum(int l, int r) {
        if (l==0) {
            T t=0;
            for (; r; r&=r-1) t+=data[r-1];
            return t;
        } else {
            return sum(0, r)-sum(0, l);
        }
    }
};


int n, m;
LL a[100010];
int main(){
  scanf("%d", &n);
  Fenwick<LL> f[6][10];
  for (int i=1; i<6; i++) for (int j=0; j<i*2; j++) f[i][j]=Fenwick<LL>(n);
  
  for (int i=0; i<n; i++) {
	cin>>a[i];
	for (int j=1; j<6; j++) {
	  f[j][i%(j*2)].add(i, a[i]);
	}
  }
  scanf("%d", &m);
  for (int i=0; i<m; i++) {
	int t;
	scanf("%d", &t);
	if (t==1) {
	  int p; LL v;
	  cin>>p>>v;
	  p--;
	  for (int j=1; j<6; j++) {
		f[j][p%(j*2)].add(p, v-a[p]);
	  }
	  a[p]=v;
	} else {
	  int l, r, z, d=1, x;
	  scanf("%d%d%d", &l, &r, &z);
	  l--; r--;
	  x=(z-1)*2;
	  
	  LL ans=0, p=1;
	  for (int j=0; j<x; j++) {
		ans+=p*f[z-1][(j+l)%x].sum(l, r+1);
		if (p==z) d=-1;
		p+=d;
	  }
	  cout<<ans<<endl;
	}
  }
  return 0;
}