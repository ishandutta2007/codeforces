#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
char tmp[10000];
string classes[3]={"weapon","armor","orb"};
map<string,int> nt;
struct XD{//item
    string name;
    int cl;
    int val;
    int size;
    void get(int q){
	int i;
	scanf("%s",tmp);
	name=tmp;
	nt[name]=q;
	scanf("%s",tmp);
	for(i=0;i<3;i++){
	    int x;
	    scanf("%d",&x);
	    if(classes[i]==tmp){
		cl=i;
		val=x;
	    }
	}
	scanf("%d",&size);
    }
    vector<int> ls;
}in[110];
string tt[3]={"gladiator", "sentry","physician"};
struct XDD{
    string name;
    int cl;
    int bo;
    int home;
    int id;
    void get(){
	scanf("%s",tmp);
	name=tmp;
	scanf("%s",tmp);
	for(int i=0;i<3;i++)if(tt[i]==tmp)cl=i;
	scanf("%d",&bo);
	scanf("%s",tmp);
	home=nt[tmp];
    }
    bool operator<(const XDD& b)const{
	return bo>b.bo;
    }
}res[1010];
vector<XDD> resl[3];
bool del[1010];
int n,m;
int main(){
    int i,j;
    scanf("%d",&n);
    int totsize=0;
    for(i=0;i<n;i++){
	in[i].get(i);
	totsize+=in[i].size;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
	res[i].get();
	res[i].id=i;
    }
    if(totsize==m){
	int mp[3]={-1,-1,-1};
	int mx[3]={-1,-1,-1};
	for(i=0;i<n;i++){
	    for(j=0;j<m;j++)if(res[j].home==i&&res[j].cl==in[i].cl)in[i].val+=res[j].bo;
	    if(in[i].val>mx[in[i].cl]){
		mx[in[i].cl]=in[i].val;
		mp[in[i].cl]=i;
	    }
	}
	for(i=0;i<3;i++){
	    printf("%s %d",in[mp[i]].name.c_str(),in[mp[i]].size);
	    for(j=0;j<m;j++)if(res[j].home==mp[i])printf(" %s",res[j].name.c_str());
	    puts("");
	}
    }else{
	for(i=0;i<m;i++)resl[res[i].cl].push_back(res[i]);
	for(i=0;i<3;i++)sort(resl[i].begin(),resl[i].end());
	int mp[3]={-1,-1,-1};
	int mx[3]={-1,-1,-1};
	for(i=0;i<n;i++){
	    int val=in[i].val;
	    int cl=in[i].cl;
	    for(j=0;j<resl[cl].size()&&j<in[i].size;j++)val+=resl[cl][j].bo;
	    if(val>mx[cl]){
		mx[cl]=val;
		mp[cl]=i;
	    }
	}
	for(i=0;i<3;i++){
	    int ii=mp[i],cl=in[ii].cl;
	    int cnt=min((int)resl[cl].size(),in[ii].size);
	    for(j=0;j<cnt;j++){
		in[ii].ls.push_back(resl[cl][j].id);
		del[resl[cl][j].id]=1;
	    }
	}
	for(i=0;i<m;i++)if(!del[i]){
	    for(j=0;j<n;j++)if(in[j].ls.size()<in[j].size){
		in[j].ls.push_back(i);
		break;
	    }
	}
	for(i=0;i<3;i++){
	    int ii=mp[i],cl=in[ii].cl;
	    printf("%s %d",in[ii].name.c_str(),in[ii].ls.size());
	    for(j=0;j<in[ii].ls.size();j++)printf(" %s",res[in[ii].ls[j]].name.c_str());
	    puts("");
	}
    }
}