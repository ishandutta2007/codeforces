#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
#define DEBUG
#endif
const int maxn=5123;
int n, a[maxn], cnt, cur, ccnt;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	for(int i=n-1; i>=0; i--){
		if(a[i]!=cur){
			cnt=max(cnt, ccnt);
			ccnt=0;
		}
		cur=a[i];
		ccnt++;
	}
	cnt=max(cnt, ccnt);
	cout<<cnt<<endl;
	return 0;
}