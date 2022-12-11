#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

ld dist(ld ax,ld ay,ld bx,ld by){
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int main(){
    fastIO;
    ld R,x1,y1,x2,y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    if(dist(x1,y1,x2,y2)>R){//OUTSIDE OF HOUSE
        cout << x1 << " " << y1 << " " << R;
        return 0;
    }
    ld v1 = abs(x1-x2);
    ld v2 = abs(y2-y1);
    ld rad = dist(x1,y1,x2,y2)+R;
    rad/=2;
    if(v1!=0.0)
        v2/=v1; // for each x value y increases by v2/v1
    else
        v2=0;
    ld yp;
    if(x1==x2){
        if(y2>=y1)
            yp=y2-rad;
        else
            yp=y2+rad;
        cout << fixed << setprecision(8) << x1 << " " << yp << " " << rad;
        return 0;
    }
    ld cx = 0,cy = 0;
    ld l = 0,r = R,m;
    for(int inc = 0;inc<1000;inc++){
        m = (l+r)/2;
        if(x2>=x1)
            cx = x1 - m;
        else
            cx = x1 + m;
        if(y2>=y1)
            cy = y1 - (m * v2);
        else
            cy = y1 + (m * v2);
        if(dist(cx,cy,x2,y2)>rad)
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(8) << cx << " " << cy << " " << rad;
    return 0;
}