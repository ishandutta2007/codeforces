#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<vector<int> > ans;
map<int,int> XD;
vector<int> cnt[100100];
int main(){
   int n,i,j;
   scanf("%d",&n);
   while(n--){
      int a;
      scanf("%d",&a);
      XD[a]++;
   }
   map<int,int>::iterator it;
   int mn = 0;
   for(it=XD.begin();it!=XD.end();it++){
      cnt[it->second].push_back(it->first);
      mn=max(mn,it->second);
   }
   while(1){
      int a=cnt[mn][cnt[mn].size()-1],ac=mn;
      cnt[mn].pop_back();
      while(mn>0&&cnt[mn].size()==0)mn--;
      if(mn==0)break;
      int b=cnt[mn][cnt[mn].size()-1],bc=mn;
      cnt[mn].pop_back();
      while(mn>0&&cnt[mn].size()==0)mn--;
      if(mn==0)break;
      int c=cnt[mn][cnt[mn].size()-1],cc=mn;
      cnt[mn].pop_back();
      while(mn>0&&cnt[mn].size()==0)mn--;
      vector<int> tmp;
      tmp.push_back(a);
      tmp.push_back(b);
      tmp.push_back(c);
      ans.push_back(tmp);
      cnt[ac-1].push_back(a);
      cnt[bc-1].push_back(b);
      cnt[cc-1].push_back(c);
      if(mn<ac-1)mn=ac-1;
   }
   for(i=0;i<ans.size();i++)sort(ans[i].begin(),ans[i].end());
   printf("%d\n",ans.size());
   for(i=0;i<ans.size();i++)for(j=2;j>=0;j--)printf("%d%c",ans[i][j],(j==0)?'\n':' ');
}