#include <iostream>
#include <fstream>

using namespace std;
const int maxn=801;
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
#endif
int n, a[maxn], res=361;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		a[i+n]=a[i];
	for(int i=0; i<n; i++){
		int fst=0, rl;
		for(int j=0; j<n; j++){
			if(fst<=180&&fst+a[i+j]>=180){
				rl=min(180-fst, fst+a[i+j]-180);
				res=min(2*rl, res);
				break;
			}
			fst+=a[i+j];
		}
	}
	cout<<res<<endl;
	return 0;
}