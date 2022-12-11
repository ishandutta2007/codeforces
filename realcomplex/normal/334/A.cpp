#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;
	int sk[n][n];
	int num = 1;
	for(int i = 0;i<n;i++){
        if(i%2 == 0){
            for(int x = 0;x<n;x++){
                sk[i][x] = num;
                num++;
            }
        }
        else{
            for(int x = n-1;x>=0;x--){
                sk[i][x] = num;
                num++;
            }
        }
	}
	for(int i = 0;i<n;i++){
        for(int x = 0;x<n;x++){
            cout << sk[x][i] << " ";
        }
        cout << "\n";
	}
	return 0;
}