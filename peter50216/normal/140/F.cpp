#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
struct XD{
   long long x,y;
   XD( long long xx=0, long long yy=0):x(xx),y(yy){}
   bool operator<(const XD& b)const{
      return x==b.x?y<b.y:x<b.x;
   }
}in[201000];
set<XD> ans;
int n,k;
inline bool solve(int cx,int cy){
   int i,j;
   i=0;j=n-1;
   int hasc=0;
   int up=0;
   while(i<=j){
      if(i==j){
         if(in[i].x==cx/2&&in[i].y==cy/2){
            hasc=1;
            i++;j--;
         }else{
            up++;
            i++;j--;
         }
      }else{
         if(in[i].x==cx/2&&in[i].y==cy/2){
            hasc=1;
            i++;
         }else if(in[j].x==cx/2&&in[j].y==cy/2){
            hasc=1;
            j--;
         }else{
            long long x1=in[i].x,y1=in[i].y;
            int x2=in[j].x,y2=in[j].y;
            long long xx=cx-x1,yy=cy-y1;
            if(xx==x2&&yy==y2){
               i++;j--;
            }else{
               up++;
               if(in[j]<XD(xx,yy)){
                  i++;
               }else{
                  j--;
               }
            }
         }
      }
      if(up>k)return 0;
   }
   return 1;
}
int main(){
   int i,j;
   scanf("%d%d",&n,&k);
   for(i=0;i<n;i++){
      int x,y;
      scanf("%d%d",&x,&y);
      x*=2;y*=2;
      in[i].x=x;in[i].y=y;
   }
   if(k>=n){
      puts("-1");
      return 0;
   }
   sort(in,in+n);
   for(i=0;i<=k;i++){
      for(j=n-1;j>=n-k-1+i;j--){
         if(i>j)continue;
         int cx=in[i].x+in[j].x, cy=in[i].y+in[j].y;
         if(solve(cx,cy))ans.insert(XD(cx/2,cy/2));
      }
   }
   printf("%d\n",ans.size());
   set<XD>::iterator it;
   for(it=ans.begin();it!=ans.end();it++){
      printf("%lf %lf\n",(*it).x/2.0,(*it).y/2.0);
   }
}