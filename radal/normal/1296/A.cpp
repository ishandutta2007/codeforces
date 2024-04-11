#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string ans[t];
	for (int i=0; i<t; i++){
		int n=0;
		cin >> n;
		int ta=0 , tb=0;
		for (int j=0; j<n; j++){
			int x;
			cin >> x;
			if (x%2 == 1){
				ta+=1;
			}
			else{
				tb+=1;
			}
		}
		if (ta%2 == 1 || (tb >0 && ta>0)){
			ans[i]="YES";
		}
		else{
			ans[i]="NO";
		}
	}
	for (int i=0; i<t; i++){
		cout<<ans[i]<<endl;
	}
}