#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, m, xx, yy, b[4], k, sum;
vector<int> sz[c];

int lcalc(int s, int kezd, int veg) {
    if (sz[s].size()==0 ||sz[s].back()<=veg || sz[s][0]>kezd) {
        return veg+1;
    }
    int lo=0, hi=sz[s].size(), mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (sz[s][mid]<kezd) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    return max(veg, sz[s][lo])+1;
}

int fcalc(int s, int kezd, int veg) {
    if (sz[s].size()==0 || sz[s].back()<kezd || sz[s][0]>=veg) {
        return veg-1;
    }
    int lo=-1, hi=sz[s].size(), mid;
    hi--;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (sz[s][mid]>kezd) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    return min(sz[s][hi], veg)-1;
}



int st(int a) {
    int s=0;
    if (a==0) {
        s=lcalc(n+yy, xx, b[0]);
    }
    if (a==1) {
        s=fcalc(xx, yy, b[1]);
    }
    if (a==2) {
        s=fcalc(n+yy, xx, b[2]);
    }
    if (a==3) {
        s=lcalc(xx, yy, b[3]);
    }
    b[a]=s;
    return (a%2 ? abs(s-yy) : abs(s-xx));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b+n].push_back(a);
    }
    b[0]=1, b[1]=m+1, b[2]=n+1, b[3]=0;
    xx=1, yy=1, sum=1;
    for (int i=1; i<=n+m; i++) {
        sort(sz[i].begin(), sz[i].end());
    }
    for (int i=1; ; i++) {
        int ii=i%4, s=st(ii);
        if (i>1 && s==0) {
            break;
        }
        //cout << "lepes " << i << " " << s << "\n";
        sum+=s;
        if (ii==0 || ii==3) {
            s*=-1;
        }
        (ii%2 ? yy+=s : xx+=s);
    }
    cout << (sum+k==n*m ? "YES" : "NO") << "\n";
    return 0;
}
/*
3 3 8
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
*/