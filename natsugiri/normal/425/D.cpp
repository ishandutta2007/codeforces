#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;

typedef long long LL;

typedef map<int, vector<pair<int, int> > > MapV;
typedef MapV::iterator IT;


int N, X[100010], Y[100010];
MapV MX, MY, MD;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d%d", X+i, Y+i);


    
    for (int i=0; i<N; i++) {
	MX[Y[i]].push_back(make_pair(X[i], i));
	MY[X[i]].push_back(make_pair(Y[i], i));
	MD[X[i]-Y[i]].push_back(make_pair(X[i]+Y[i], i));
    }
	
    for (IT it=MX.begin(); it!=MX.end(); it++)
	sort(it->second.begin(), it->second.end());
    for (IT it=MY.begin(); it!=MY.end(); it++)
	sort(it->second.begin(), it->second.end());
    for (IT it=MD.begin(); it!=MD.end(); it++)
	sort(it->second.begin(), it->second.end());


    int ans = 0;
    for (int i=0; i<N; i++) {
    	const vector<pair<int,int> > &xv = MX[Y[i]];
    	const vector<pair<int,int> > &yv = MY[X[i]];
    	const vector<pair<int,int> > &dv = MD[X[i]-Y[i]];
    	const int xi = lower_bound(xv.begin(), xv.end(), make_pair(X[i], -1)) - xv.begin();
    	const int yi = lower_bound(yv.begin(), yv.end(), make_pair(Y[i], -1)) - yv.begin();
    	const int di = lower_bound(dv.begin(), dv.end(), make_pair(X[i]+Y[i], -1)) - dv.begin();

	int xj=xi+1, yj=yi+1, dj=di+1;
	for (;;) {
	    if (xj >= (int)xv.size()) break;
	    if (yj >= (int)yv.size()) break;
	    if (dj >= (int)dv.size()) break;

	    int xf = xv[xj].first;
	    int yf = yv[yj].first;
	    int df = dv[dj].first;
	    int xl = xf-X[i];
	    int yl = yf-Y[i];
	    int dl = df-(X[i]+Y[i]);
	    if (xl == yl && xl*2 == dl) {
		ans++;
		xj++; yj++; dj++;
	    } else if (xl <= yl && xl*2 <= dl) {
		xj++;
	    } else if (yl <= xl && yl*2 <= dl) {
		yj++;
	    } else {
		dj++;
	    }
	}
    }
    
    printf("%d\n", ans);

    return 0;
}