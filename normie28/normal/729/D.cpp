#include <bits/stdc++.h>
 
using namespace std;
 
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n,a,b,k;
	cin >> n >> a >> b >> k;
	string st;
	cin >> st;
	st+='1';
	vector<int> I;
	vector<int> C;
	int ant=-1;
	int t=0;
	for (int i=0;i<n+1;i++){
		if(st[i]=='1'){
			ant++;
			if(i-ant>0){
				I.push_back(ant);
				C.push_back(i-ant);
				t+=(i-ant)/b;
				ant=i;
			}
		}
	}
	t-=(a-1);
	cout << t << endl;
	vector<int> R;
	for (int i=0;i<C.size();i++){
		while(t>0 && C[i]-b>=0){
			C[i]-=b;
			cout << I[i]+b << " ";
			I[i]+=b;
			t--;
		}
  }
	cout << endl;
}