#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = 509;
char conf[N][N];

int main(){
    int r,c;
    cin >> r >> c;	
    for(int i = 1;i<=r;i++)
    	for(int j= 1;j<=c;j++)
    		cin >> conf[i][j];
    for(int i = 1;i<=r;i++){
    	for(int j = 1;j<=c;j++){
    		if(conf[i][j] == 'S'){
    			if(conf[i+1][j] == 'W' or conf[i-1][j] == 'W' or conf[i][j+1] == 'W' or conf[i][j-1] == 'W'){
    				cout << "No";
    				return 0;
    			}
    		}
    	}
    }
    cout << "Yes\n";
    for(int i = 1;i<=r;i++){
    	for(int j = 1;j<=c;j++){
    		if(conf[i][j] == '.')
    			cout << "D";
    		else
    			cout << conf[i][j];
    	}
    	cout << "\n";
    }
    return 0;
}