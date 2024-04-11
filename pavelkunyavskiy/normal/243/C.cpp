#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> xs;
vector<int> ys;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
const string name = "URDL";


char c[1100];
int d[1100];
int n;
int mx,my;

int getid(char c){
	for (int i = 0; i < 4; i++)
		if (name[i] == c)
			return i;
	assert(false);
}

char can[5100][5100];



void go(int x,int y){
	if (x < 0 || y < 0 || x >= mx || y >= my)
		return;
	if (can[x][y])
		return;
	can[x][y] = 2;
	go(x+1,y);
	go(x,y+1);
	go(x-1,y);
	go(x,y-1);	
}

int getsize(const vector<int>& a,int id){
	return a[id] - a[id-1];
}         

int getid(const vector<int>& a,int val){
	int temp = lower_bound(a.begin(),a.end(),val) - a.begin();
	return temp;
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    int x,y;
    x = y = 0;
    xs.pb(0);
    ys.pb(0);
    xs.pb(1);
    ys.pb(1);
    xs.pb(-1);
    ys.pb(-1);
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
    	scanf(" %c %d",&c[i],&d[i]);
    	int id = getid(c[i]);
    	x += dx[id] * d[i];
		y += dy[id] * d[i];
		xs.pb(x);
		xs.pb(x+1);
		xs.pb(x-1);
		ys.pb(y);
		ys.pb(y+1);
		ys.pb(y-1);
    }

    xs.pb(1<<30);xs.pb(-xs.back());     
    ys.pb(1<<30);ys.pb(-ys.back());


                           

    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());

    mx = xs.size();
    my = ys.size();

    x = y = 0;
    int xid,yid;
    xid = getid(xs,0);
    yid = getid(ys,0);

    can[xid][yid] = 1;

    for (int i = 0; i < n; i++){
    	int id = getid(c[i]);
    	int nx = x + dx[id] * d[i];
		int ny = y + dy[id] * d[i];

		int nxid = getid(xs,nx);
		int nyid = getid(ys,ny);

		for (int j = xid; j <= nxid; j++) can[j][yid] = 1;
		for (int j = nxid; j <= xid; j++) can[j][yid] = 1;
		for (int j = yid; j <= nyid; j++) can[xid][j] = 1;
		for (int j = nyid; j <= yid; j++) can[xid][j] = 1;


		x = nx;
		y = ny;
		xid = nxid;
		yid = nyid;
    }

    go(0,0);

    ll ans = 0;      
    /*for (int i = 0; i < (int)xs.size(); i++)
    	cerr << xs[i] <<" ";
    cerr<<endl;      
    for (int i = 0; i < (int)ys.size(); i++)
    	cerr << ys[i] <<" ";
    cerr<<endl;
    cerr << mx <<" "<<my << endl;

    for (int i = 0; i < mx; i++,cerr<<endl)
    	for (int j = 0; j < my; j++)
    		cerr << char(can[i][j]+'0'); */

    for (int i = 0; i < mx; i++)
    	for (int j = 0; j < my; j++)
    		if (can[i][j] != 2){
//    		    if (getsize(xs,i) && getsize(ys,j))
//	    		    cerr << i <<" "<<j <<" "<< getsize(xs,i) <<" "<< getsize(ys,j) <<endl;
    			ans += getsize(xs,i) * 1LL * getsize(ys,j);
    		}
    cout << ans << endl;      
    return 0;
}