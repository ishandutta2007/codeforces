#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
//orz mqy
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
int n,m,k;
bool check(int x){
	//left : k-1 rgt: n-k
	long long sum=0LL;
	if (x>=k){
		sum+=(LL)(2*x-k+1)*(LL)k/2;
	}
	else{
		sum+=(LL)(1+x)*x/2;
		sum+=(LL)(k-x);
	}
	if (x>n-k){
		sum+=(LL)(x-n+k+x-1)*(LL)(n-k)/2;
	}
	else{
		sum+=(LL)(x)*(LL)(x-1)/2;
		sum+=(LL)(n-k-x+1);
	}
	//if (x==1) cout<<sum;
	return sum<=(LL)m;
	
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	int hi=m,lo=0;
	while (lo<hi){
	//	cout<<lo<<hi<<endl;;
		int mid=(hi+lo+1)/2;
		if (check(mid)){
			lo=mid;
		}
		else{
			hi=mid-1;
		}
	}
	printf("%d\n",hi);
}