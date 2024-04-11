#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
char getLastVowel(string ch){
    int len=ch.size();
    for (int i=len-1;i>=0;--i)
        if (ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u') return ch[i];
    return '\0';
}
int getVowelNum(string ch){
    int len=ch.size();
    int tot=0;
    for (int i=0;i<len;++i)
        if (ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u') ++tot;
    return tot;
}
map<int,map<char, vector<string> > > Map;
string p1[100001],p2[100001];
string ans[4];
int c1,c2;
string ch;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;++i){
        string tmp;
        cin>>ch;
        Map[getVowelNum(ch)][getLastVowel(ch)].push_back(ch);
    }
    c1=c2=0;
    for (auto i:Map){
        for (auto j:i.second){
            for (int k=0;k+1<j.second.size();k+=2){
                p1[c1]=j.second[k];
                p1[c1+1]=j.second[k+1];
                c1+=2;
            }
            if (j.second.size()%2){
                p2[c2]=j.second[j.second.size()-1];
                ++c2;
            }
        }
        if (c2%2) --c2;
    }
    int len=min((c1+c2)/4,c1/2);
    cout<<len<<endl;
    --c1;--c2;
    for (int i=0;i<len;++i){
        if (c2<0) { ans[0]=p1[c1]; ans[2]=p1[c1-1]; c1-=2;}
        else { ans[0]=p2[c2]; ans[2]=p2[c2-1]; c2-=2;}
        ans[1]=p1[c1]; ans[3]=p1[c1-1]; c1-=2;
        cout<<ans[0].c_str()<<' '<<ans[1].c_str()<<'\n'<<ans[2].c_str()<<' '<<ans[3].c_str()<<endl;
    }
}