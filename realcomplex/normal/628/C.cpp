#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;	
	cin >> n >> k;
	char v[n];
	cin >> v;
	int l = 0,r = 0;
	for(int j = 0;j<n;j++){
		l = v[j]-'a';
		r = 'z'-v[j];
		if(r>l){
			if(r<=k){
				v[j] = 'z';
				k-=r;
			}
			else{
				if(k==0)continue;
				v[j] += k;
				k = 0;
			}	
		}
		else{
			if(l<=k){
				v[j] = 'a';
				k-=l;
			}
			else{
				if(k==0)continue;
				v[j]-=k;
				k = 0;
			}
		}
	}
	if(k!=0)cout << -1 << "\n";
	else
		for(int i = 0;i<n;i++)
			cout << v[i];
	return 0;
}