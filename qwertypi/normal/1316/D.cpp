#include <bits/stdc++.h>
#define IOS cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);

char in[1 << 27];
char const* o ;
 
void load(){  o = in;   in [   fread(in,  1,  sizeof(in ) - 4 ,  stdin ) ] = 0; }
 
int readInt(){
      int u = 0;
      bool neg = false;
      while( *o && *o <= 32) ++o ; //  skip spaces
    
    if(*o == '-'){
        neg = true;
        o++;
    }
      while ( *o >='0' && *o <='9') u = (u << 3) + (u << 1) + (*o++ -'0');
      if(neg){
          return -u;
      }else{
          return u;
      }
}

using namespace std;

struct Point{
	int x, y;
	Point(int x, int y) { this->x = x, this->y = y; }
};

int A[1000][1000][2];
char ans[1000][1000];

bool visited[1000][1000];

int n;
int x = -2, y = -2;
void dfs(int i, int j){
    visited[i][j] = 1;
	if(i != 0 && A[i - 1][j][0] == x && A[i - 1][j][1] == y){
	    if(!visited[i - 1][j]){
	      	ans[i - 1][j] = 'D';
		    dfs(i - 1, j);  
	    }
	}
	if(i != n - 1 && A[i + 1][j][0] == x && A[i + 1][j][1] == y){
	    if(!visited[i + 1][j]){
    		ans[i + 1][j] = 'U';
    		dfs(i + 1, j);
	    }
	}
	if(j != 0 && A[i][j - 1][0] == x && A[i][j - 1][1] == y){
	    if(!visited[i][j - 1]){
    		ans[i][j - 1] = 'R';
    		dfs(i, j - 1);
	    }
	}
	if(j != n - 1 && A[i][j + 1][0] == x && A[i][j + 1][1] == y){
	    if(!visited[i][j + 1]){
	  		ans[i][j + 1] = 'L';
		    dfs(i, j + 1);
	    }
	}
}

int32_t main(){
	load();
	n = readInt();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j][0] = (readInt() - 1), A[i][j][1] = (readInt() - 1);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(A[i][j][0] == -2){
				if(i != 0 && A[i - 1][j][0] == -2){
					ans[i][j] = 'U';
				}else if(i != n - 1 && A[i + 1][j][0] == -2){
					ans[i][j] = 'D';
				}else if(j != 0 && A[i][j - 1][0] == -2){
					ans[i][j] = 'L';
				}else if(j != n - 1 && A[i][j + 1][0] == -2){
					ans[i][j] = 'R';
				}else{
					cout << "INVALID" << endl;
					exit(0);
				}
			}
		}
	}
	vector<Point> VP;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(A[i][j][0] != -2){
				VP.push_back({A[i][j][0], A[i][j][1]});
			}
		}
	}
	
	for(auto i : VP){
		if(visited[i.x][i.y]){
			continue;
		}else{
			x = i.x, y = i.y;
			ans[x][y] = 'X';
			if(A[x][y][0] != x || A[x][y][1] != y){
			    cout << "INVALID" << endl;
			    return 0;
			}
			dfs(i.x, i.y);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!ans[i][j]){
				cout << "INVALID" << endl;
				return 0;
			}
		}
	}
	
	cout << "VALID" << endl;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
}