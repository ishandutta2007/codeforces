#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

int H, W;
string field[510];

bool use[510][510];
vector<string>ans;


void change(char c, int y, int x) {
    char str[99];
    sprintf(str, "%c %d %d\n", c, y+1, x+1);
    ans.push_back(str);
    if (c=='D') c='.';
    field[y][x]=c;
}
int main() {
    scanf("%d%d", &H, &W);
    for (int i=0; i<H; i++) cin>>field[i];

    stack<int>X, Y;
    vector<int>dfs_x, dfs_y;
    
    for (int i=0; i<H; i++) {
	for (int j=0; j<W; j++) {
	    if (use[i][j] || field[i][j]=='#') continue;
	    use[i][j]=true;
	    dfs_x.push_back(j);
	    dfs_y.push_back(i);
	    X.push(j);
	    Y.push(i);
	    for (;!X.empty();) {
		int x=X.top(), y=Y.top(); X.pop(); Y.pop();
		for (int d=0; d<4; d++) {
		    int xx=x+dx[d], yy=y+dy[d];
		    if (xx<0 || W<=xx || yy<0 || H<=yy || use[yy][xx] || field[yy][xx]=='#') continue;
		    use[yy][xx]=true;
		    dfs_x.push_back(xx);
		    dfs_y.push_back(yy);
		    X.push(xx);
		    Y.push(yy);
		}
	    }
	}
    }
    for (int i=0; i<int(dfs_x.size()); i++) {
	int x=dfs_x[dfs_x.size()-1-i], y=dfs_y[dfs_x.size()-1-i];
	if (field[y][x]=='B') {
	    change('D', y, x);
	}
	bool b=false;
	for (int d=0; d<4; d++) {
	    int xx=x+dx[d], yy=y+dy[d];	    
	    if (xx<0 || W<=xx || yy<0 || H<=yy) continue;
	    if (field[yy][xx]=='B') b=true;
	}
	if (b) {
	    change('R', y, x);
	    continue;
	}

	b=false;
	for (int d=0; d<4; d++) {
	    int xx=x+dx[d], yy=y+dy[d];	    
	    if (xx<0 || W<=xx || yy<0 || H<=yy) continue;
	    if (field[yy][xx]=='.') {
		b=true;
		change('B', yy, xx);
		change('R', y, x);
		break;
	    }
	}
	if (field[y][x]=='.') change('B', y, x);
    }
    printf("%d\n", ans.size());
    for (int i=0; i<int(ans.size()); i++) cout<<ans[i];
    //for (int i=0; i<H; i++) cout<<field[i]<<endl;
    return 0;
}