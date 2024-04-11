#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
struct pac {long long no; long long mu;};
using namespace std;
int main()
{
	long long n,m,i,j,x,c,mm,save,cou,k,y; vector <long long> a; vector <pac> b; pac hold;
	string s;
	cin>>n>>k;
	for (i=1;i<=n;i++) {cin>>x; a.push_back(x);} 
	sort(a.begin(),a.end());
	mm=(n-1)/2;
	cou=1;
	for (i=mm+1;i<=n-1;i++) {if (a[i]==a[i-1]) cou++; else {hold.no=a[i-1]; hold.mu=cou; b.push_back(hold); cou=1;}} {hold.no=a[i-1]; hold.mu=cou; b.push_back(hold); cou=1;}
//	for (i=0;i<b.size();i++) cout<<b[i].no<<' '<<b[i].mu<<endl;
	while (k>0) {
	if (b.size()==1) {cout<<(k/b[0].mu)+b[0].no; k=0;} 
	else if ((b[1].no-b[0].no)*b[0].mu<=k) {y=(b[1].no-b[0].no)*b[0].mu; b[1].mu+=b[0].mu; b.erase(b.begin()); k-=y; if (k==0) cout<<b[0].no;} 
	else {cout<<(k/b[0].mu)+b[0].no; k=0;} 
}
	
}