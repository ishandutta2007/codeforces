#include<bits/stdc++.h>

using namespace std;

//Binary Indexed Tree
long long bsize=131072;
long long sum(long long i,vector<long long> &bit){
    long long s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
void add(long long i,long long x,vector<long long> &bit){
    while(i<=bsize){
        bit[i]+=x;
        i+=i&(-i);
    }
}

long long inv(vector<long long> &p){
	long long res=0;
	vector<long long> bit(132000,0);
	for(long long i=p.size()-1;i>=0;i--){
		res+=sum(p[i],bit);
		add(p[i],1,bit);
	}
	return res;
}

double exr(long long n){
	double res=n;
	res*=(n-1);
	return res/4.0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	vector<long long> b(132000,0);
	long long n;
	cin >> n;
	vector<long long> p(n);
	for(auto &nx : p){cin >> nx;}
	long long base=inv(p);
	long long pat=(n*(n+1))/2;
	long long tis=0;
	double res=base,rnd=0.0;
	res*=pat;
	for(long long i=n-1;i>=0;i--){
		rnd+=exr(n-i);
		tis+=sum(p[i],b);
		res-=tis;
		res+=rnd;
		add(p[i],n-i,b);
	}
	res/=pat;
	printf("%.12lf\n",res);
  return 0;
}