#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
char in[10000],fir[10000],sec[10000];
struct widget{
    long long x,y;
    long long sp,bo;
    int kind; //widget=0, hbox=1, vbox=2
    widget(){x=-1;y=-1;sp=bo=0;}
    vector<widget*> pack;
    inline void calc(){
	if(x!=-1)return;
	if(pack.size()==0){
	    x=0;y=0;return;
	}
	if(kind==1){
	    long long maxy=0;
	    long long sumx=-sp;
	    for(int i=0;i<pack.size();i++){
		pack[i]->calc();
		maxy=max(maxy,pack[i]->y);
		sumx+=pack[i]->x+sp;
	    }
	    x=sumx+2ll*bo;
	    y=maxy+2ll*bo;
	}else{
	    long long maxx=0;
	    long long sumy=-sp;
	    for(int i=0;i<pack.size();i++){
		pack[i]->calc();
		maxx=max(maxx,pack[i]->x);
		sumy+=pack[i]->y+sp;
	    }
	    y=sumy+2ll*bo;
	    x=maxx+2ll*bo;
	}
    }
};
map<string,widget*> XD;
int main(){
    int q,i;
    gets(in);
    q=atoi(in);
    while(q--){
	gets(in);
	int l=strlen(in);
	for(i=0;i<l;i++)if(in[i]==' ')break;
	if(i<l){
	    sscanf(in,"%s%s",fir,sec);
	    widget* w=new widget;
	    if(strcmp(fir,"Widget")==0){
		string ss=sec;
		string na=ss.substr(0,ss.find("("));
		int x=atoi(ss.substr(ss.find("(")+1).c_str());
		int y=atoi(ss.substr(ss.find(",")+1).c_str());
		w->x=x;
		w->y=y;
		w->kind=0;
		XD[na]=w;
	    }else if(strcmp(fir,"HBox")==0){
		w->kind=1;
		XD[sec]=w;
	    }else{
		w->kind=2;
		XD[sec]=w;
		
	    }
	}else{
	    string ss=in;
	    string na=ss.substr(0,ss.find("."));
	    string cmd=ss.substr(ss.find(".")+1,ss.find("(")-ss.find(".")-1);
	    string tar=ss.substr(ss.find("(")+1,ss.find(")")-ss.find("(")-1);
	    if(cmd=="pack"){
		(XD[na]->pack).push_back(XD[tar]);
	    }else if(cmd=="set_border"){
		XD[na]->bo=atoi(tar.c_str());
	    }else{
		XD[na]->sp=atoi(tar.c_str());
	    }
	}
    }
    for(map<string,widget*>::iterator it=XD.begin();it!=XD.end();it++){
	it->second->calc();
	printf("%s %I64d %I64d\n",(it->first).c_str(),it->second->x,it->second->y);
    }
}