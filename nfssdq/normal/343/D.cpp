/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


vector<int>vc[500001];
vector<int>vs[500001];
int nc[500001];
int lvl[500001],start[500001],endt[500001];
int t=0;
int dfs1(int ii,int p,int lv)
{
    LL ret=1;
    lvl[ii]=lv;
    t++;
    start[ii]=t;
    REP(i,vc[ii].size())
    {
        if(vc[ii][i]==p)continue;
        ret+=dfs1(vc[ii][i],ii,lv+1);
    }
    nc[ii]=ret;
    endt[ii]=t;
    return ret;
}
int cnt=0;
int grp[500001],pnt[500001];
int position[500001];
void dfs2(int ii,int p,int pos)
{
    position[ii]=pos;
    pnt[ii]=p;
    grp[ii]=cnt;
    vs[cnt].push_back(ii);
    LL v=0,pp=0;
    REP(i,vc[ii].size())
    {
        if(vc[ii][i]==p)continue;
        if(nc[vc[ii][i]]>v)
        {
            v=nc[vc[ii][i]];
            pp=vc[ii][i];
        }
    }
    if(pp!=0)dfs2(pp,ii,pos+1);
    REP(i,vc[ii].size())
    {
        if(vc[ii][i]==p || vc[ii][i]==pp)continue;
        cnt++;
        dfs2(vc[ii][i],ii,0);
    }
}


vector<int>seg[500001];
void insert(int ii,int idx,int s,int e,int v,int p)
{
    if(s==e)
    {
        seg[ii][idx]=p;
        return;
    }
    int mid=(s+e)/2;
    if(v<=mid)insert(ii,idx*2+1,s,mid,v,p);
    else if(v>mid)insert(ii,idx*2+2,mid+1,e,v,p);
    seg[ii][idx]=max(seg[ii][idx*2+1],seg[ii][idx*2+2]);
}
int query(int ii,int idx,int s,int e,int st,int ed)
{
    if(s==st && e==ed)return seg[ii][idx];
    LL mid=(s+e)/2;
    if(ed<=mid)return query(ii,idx*2+1,s,mid,st,ed);
    else if(st>mid)return query(ii,idx*2+2,mid+1,e,st,ed);
    else return max(query(ii,idx*2+1,s,mid,st,mid),query(ii,idx*2+2,mid+1,e,mid+1,ed));
}
int dfsqu(int ii,int li)
{
    if(ii==pnt[li])return 0;
    int a=grp[ii];
    if(grp[li]==a)
        return query(a,0,0,vs[a].size()-1,position[li],position[ii]);
    else return max(query(a,0,0,vs[grp[ii]].size()-1,0,position[ii]),dfsqu(pnt[vs[a][0]],li));
}

int seg1[2000001];
void insert1(int idx, int s, int e, int p, int v){
    if(s == e){
        seg1[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid)insert1(idx * 2 + 1, s, mid, p, v);
    else insert1(idx * 2 + 2, mid + 1, e, p, v);
    seg1[idx] = max( seg1[idx * 2 + 1], seg1[idx * 2 + 2] );
}
int query1(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed)return seg1[idx];
    int mid = (s + e) / 2;
    if(ed <= mid)return query1(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid)return query1(idx * 2 + 2, mid + 1, e, st, ed);
    return max( query1(idx * 2 + 1, s, mid, st, mid), query1(idx * 2 + 2, mid + 1, e, mid + 1, ed) );
}


main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,c,d,e,f,g,h = 1,x,y,z;
    scanf("%d",&a);
    REP(i,a-1)
    {
        scanf("%d %d",&c,&d);
        vc[c].push_back(d);
        vc[d].push_back(c);
    }
    dfs1(1,0,1);
    dfs2(1,0,0);
    REP(i,cnt+1)
       REP(j,4*vs[i].size()+4)seg[i].push_back(0);
    cin >> b;
    REP(i, b){
        cin >> c >> d;
        if(c == 1){
            insert(grp[d], 0, 0, vs[ grp[d] ].size() - 1, position[d], i + 1);
        }
        else if(c == 2){
            insert1(0, 1, a, start[d], i + 1);
        }
        else {
            e = dfsqu(d, 1);
            f = query1(0, 1, a, start[d], endt[d]);
            if(e > f)cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

}