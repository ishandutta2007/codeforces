//#include <senator>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
int n,m,k;
cin >> n >> m >> k;
int s = 0;
int a[n];
for(int i = 1;i <= n;i++){
	cin >> a[i];
	}	
	for(int p = 1;p<= n;p++){
		if(a[p] == 1){
			if(m > 0)
			m--;
			else{
				s++;
				}
			}
			if(a[p] == 2){
				if(k > 0)
					k--;
				else{
					if(m > 0){
						m--;
						}
						else{
							s++;
					}
							}}
		}
		cout << s << endl;
	
}