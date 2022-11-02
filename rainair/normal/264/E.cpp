// #include <algorithm>
// #include <iostream>
// #include <cstring>
// #include <climits>
// #include <cstdio>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>
// #include <queue>
// #include <stack>
// #include <map>
// #include <set>

// #define Re register
// #define LL long long
// #define U unsigned
// #define FOR(i,a,b) for(Re int i = a;i <= b;++i)
// #define ROF(i,a,b) for(Re int i = a;i >= b;--i)
// #define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
// #define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
// #define CLR(i,a) memset(i,a,sizeof(i))
// #define BR printf("--------------------\n")
// #define DEBUG(x) std::cerr << #x << '=' << x << std::endl

// const int MAXN = 100000 + 5;

// namespace fastIO{ 
//     #define BUF_SIZE 100000 
//     #define OUT_SIZE 100000 
//     #define ll long long 
//     bool IOerror=0; 
//     inline char nc(){ 
//         static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
//         if (p1==pend){ 
//             p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
//             if (pend==p1){IOerror=1;return -1;} 
//         } 
//         return *p1++; 
//     } 
//     inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
//     inline void read(int &x){ 
//         bool sign=0; char ch=nc(); x=0; 
//         for (;blank(ch);ch=nc()); 
//         if (IOerror)return; 
//         if (ch=='-')sign=1,ch=nc(); 
//         for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
//         if (sign)x=-x; 
//     } 
//     inline void read(ll &x){ 
//         bool sign=0; char ch=nc(); x=0; 
//         for (;blank(ch);ch=nc()); 
//         if (IOerror)return; 
//         if (ch=='-')sign=1,ch=nc(); 
//         for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
//         if (sign)x=-x; 
//     } 
//     #undef ll 
//     #undef OUT_SIZE 
//     #undef BUF_SIZE 
// }; 
// using namespace fastIO;

// int f[MAXN],h[MAXN],N,M;

// struct SegmentTree *New(int ,int ,SegmentTree *,SegmentTree *);

// struct SegmentTree{
//     int l,r,max;
//     SegmentTree *lc,*rc;

//     static SegmentTree *build(int l,int r){
//         int mid = (l + r) >> 1;
//         return (l == r) ? New(l,r,NULL,NULL) : New(l,r,build(l,mid),build(mid+1,r));
//     }

//     inline void pushup(){
//         max = std::max(lc->max,rc->max);
//     }

//     inline void update1(int pos){
//         if(l == r && l == pos){
//             max = f[pos];
//             return;
//         }
//         int mid = (l + r) >> 1;
//         if(pos <= mid) lc->update1(pos);
//         else rc->update1(pos);
//         pushup();
//     }

//     inline void update2(int pos,bool x){
//         if(l == r && l == h[pos] + M){
//             if(x) max = f[x];
//             else max = 0;
//             return;
//         }
//         int mid = (l + r) >> 1;
//         if(h[pos] + M <= mid) lc->update2(pos,x);
//         else rc->update2(pos,x);
//         pushup();
//     }

//     inline int query(int pos){
//         if(l >= pos) return max;
//         int mid = (l + r) >> 1;
//         if(pos > mid) return rc->query(pos);
//         return std::max(lc->query(pos),rc->query(pos));
//     }

// }pool[MAXN<<3],*frog = pool,*segt1,*segt2;

// SegmentTree *New(int l,int r,SegmentTree *lc,SegmentTree *rc){
//     SegmentTree *ret = ++frog;
//     ret->l = l;ret->r = r;
//     ret->max = 0;
//     ret->lc = lc;ret->rc = rc;
//     return ret;
// }

// int tree[MAXN];

// #define lowbit(x) x&-x

// inline void add(int pos,int x){
//     for(int i = pos;i <= N;i += lowbit(pos))
//         tree[i] += x;
// }

// inline int calc(int pos){
//     int ret = 0;
//     for(int i = pos;i;i -= lowbit(i))
//         ret += tree[i];
//     return ret;
// }

// inline int Find(int pos){
//     int ret = 0;
//     int l = 1,r = N;
//     while(l <= r){
//         int mid = (l + r) >> 1;
//         if(pos <= calc(mid)) r = mid-1,ret = mid;
//         else l = mid + 1;
//     }
//     return ret;
// }

// std::vector<int> C;

// inline void sort(){
//     std::sort(C.begin(),C.end());
// }

// std::vector<int>::iterator I,J,T;

// int main(){
//     read(N);read(M);
//     segt1 = SegmentTree::build(1,M+10);
//     segt2 = SegmentTree::build(1,M+10);
//     FOR(turn,1,M){
//         int opt,pos;
//         read(opt);
//         if(opt & 1){
//             read(pos);read(h[pos]);
//             h[pos] -= turn;
//             add(pos,1);
//             C.push_back(pos);
//             sort();
//             DEBUG(pos+1);
//             f[pos] = segt1->query(pos+1)+1;
//             T = I = find(C.begin(),C.end(),pos);
//             for(I++;I != C.end();I++){
//                 if(h[*I] > h[pos])
//                     h[pos] = std::max(h[pos],h[*I]+1);
//             }
//             I = T;
//             if(I != C.begin()){
//                 for(I--;;I--){
//                     for(J=I,J++;J != C.end();J++){
//                         if(h[*I] < h[*J])
//                             f[*I] = std::max(f[*I],f[*J]+1);
//                     }
//                 }
//             } 
//             if(calc(N) > 10){
//                 if(calc(pos) <= 10) segt2->update2(Find(11),1);
//                 else segt2->update2(pos,1);
//             }
//         }
//         else{
//             read(pos);int t = pos;
//             pos = Find(pos);
//             add(pos,-1);
//             if(calc(N) >= 10)
//                 segt2->update2(Find(10),0);
//             I = find(C.begin(),C.end(),pos);
//             f[pos] = 0;
//             if(I == C.end()) segt1->update1(pos);
//             else C.erase(I);
//             FOR(i,1,t-1){
//                 pos = Find(i);
//                 f[pos] = segt2->query(h[pos]+M)+1;
//             }
//             ROF(i,t-1,0){
//                 pos = Find(i);
//                 FOR(j,i+1,10){ 
//                     int ppos = Find(j);
//                     if(h[pos] <= h[ppos]){
//                         f[pos] = std::max(f[pos],f[ppos]+1);
//                     }
//                 }
//                 if(h[pos]+turn > 10)
//                     segt1->update1(pos); 
//             }
//         }
//         int ans = segt1->query(1);
//         for(I = C.begin();I != C.end();I++)
//             if(ans < f[*I]) ans = f[*I];
//         printf("%d\n",ans);
//     //     ans=query(0,1,n+1,1);
//     // for (I=c.begin();I!=c.end();I++)
//     //   if (ans<dp[*I]) ans=dp[*I];
//     // printf("%d\n",ans);
//     }
//     return 0;
// }

#include <list>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
#define lowbit(x) ((x)&(-(x)))
int maxx[400005],dp[100005],tr[100005];
int maxx2[800020],ht[100005];
int n,m,M,tim,ans,x,y,xx,typ,i,j;
list <int> c;
list <int>::iterator I,J;
 
void add(int p,int l,int r,int x){
  if (l==r && l==x) {maxx[p]=dp[x]; return;}
  int mid=(l+r)>>1;
  if (x<=mid) add(p*2+1,l,mid,x);
    else add(p*2+2,mid+1,r,x);
  maxx[p]=max(maxx[p*2+1],maxx[p*2+2]);
}
 
int query(int p,int l,int r,int x){
  if (l>=x) return maxx[p];
  int mid=(l+r)>>1;
  if (mid<x) return query(p*2+2,mid+1,r,x);
    else return max( query(p*2+1,l,mid,x), query(p*2+2,mid+1,r,x) );
}
 
int ADD(int x,int flag){
  for (int i=x;i<=n;i+=lowbit(i))
    tr[i]+=flag;
}
 
int GET(int x){
  int ret=0;
  for (int i=x;i>0;i-=lowbit(i))
    ret+=tr[i];
  return ret;
}
 
int calc(int x){
  int ret=0;
  for (int l=1,r=n,mid=(l+r)>>1;l<=r;mid=(l+r)>>1){
    if (x<=GET(mid)) ret=mid, r=mid-1;
      else l=mid+1;
  }
  return ret;
}
 
void add2(int p,int l,int r,int x,bool flag){
  if (l==r && l==ht[x]+m){
    if (flag) maxx2[p]=dp[x];
      else maxx2[p]=0;
    return;
  }
  int mid=(l+r)>>1;
  if (ht[x]+m<=mid) add2(p*2+1,l,mid,x,flag);
    else add2(p*2+2,mid+1,r,x,flag);
  maxx2[p]=max(maxx2[p*2+1],maxx2[p*2+2]);
}
 
int query2(int p,int l,int r,int x){
  if (l>=x) return maxx2[p];
  int mid=(l+r)>>1;
  if (x>mid) return query2(p*2+2,mid+1,r,x);
    else return max( query2(p*2+1,l,mid,x), query2(p*2+2,mid+1,r,x) );
}
 
int main(){
  //freopen("264E.in","r",stdin);
  //freopen("264E.out","w",stdout);
  scanf("%d%d",&n,&m);
  M=m+10;
  for (tim=1;tim<=m;tim++){
 
    for (I=c.begin();I!=c.end();I++)
      if (ht[*I]+tim>10)
        {add(0,1,n+1,*I); c.erase(I); break;}
 
    scanf("%d",&typ);
    
    if (typ==1){
      scanf("%d",&x);
      scanf("%d",&ht[x]);
      ht[x]-=tim;
      ADD(x, 1);
      c.push_back(x);
      c.sort();
      
      dp[x]=query(0,1,n+1,x+1)+1;
      I=find(c.begin(),c.end(),x);
      for (I++;I!=c.end();I++)
        if (ht[*I]>ht[x])
          dp[x]=max(dp[x],dp[*I]+1);
      
      I=find(c.begin(),c.end(),x);
      if (I!=c.begin())
      for (I--;;I--){
        for (J=I,J++;J!=c.end();J++)
          if (ht[*I]<ht[*J])
            dp[*I]=max(dp[*I],dp[*J]+1);
        if (GET(*I)>10) add2(0,1,M,*I,1);
        if (I==c.begin()) break;
      }
      
      if (GET(n)>10){
        if (GET(x)<=10) add2(0,1,M,calc(11),1);
          else add2(0,1,M,x,1);
      }
      
    } else
    if (typ==2){
      scanf("%d",&y);
      x=calc(y); ADD(x, -1);
      if (GET(n)>=10)
        add2(0,1,M,calc(10),0);
      I=find(c.begin(),c.end(),x);
      dp[x]=0;
      if (I==c.end()) add(0,1,n+1,x);
        else c.erase(I);
      
      //calc it again
      for (i=1;i<y;i++){
        x=calc(i);
        dp[x]=query2(0,1,M,ht[x]+m)+1;
      }
      for (i=y-1;i>0;i--){
        x=calc(i);
        for (j=i+1;j<=10;j++){
          xx=calc(j);
          if (ht[x]<ht[xx])
            dp[x]=max(dp[x],dp[xx]+1);
        }
        if (ht[x]+tim>10)
          add(0,1,n+1,x);
      }
      
    }
    ans=query(0,1,n+1,1);
    for (I=c.begin();I!=c.end();I++)
      if (ans<dp[*I]) ans=dp[*I];
    printf("%d\n",ans);
    
    //for (i=1;i<=tim;i++)
    //  printf("%d ",ht[ calc(i) ]+tim);
    //printf("\n");
    //printf("%d\n",calc(3));
  }
  return 0;
}