#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	set<string>nam;
	string cur;
	for(int i = 0;i<n;i++){
		cin >> cur;
		for(int j = cur.size()-1;j>=0;j--){
			if(j>0){
				if(cur[j] == 'h' && cur[j-1] == 'k'){
					cur.erase(j-1,1);
				}
				else if(cur[j] == 'u'){
					cur.replace(j,1,"oo");
				}
			}
			else{
				if(cur[j] == 'u') cur.replace(j,1,"oo");
			}
		}	
		//cout << endl << i << " " << cur;
		nam.insert(cur);
	}
	cout <<nam.size() << endl;
	return 0;
}