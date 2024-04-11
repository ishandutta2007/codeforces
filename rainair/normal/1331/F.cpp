#include<bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

std::map<std::string,int> S;

inline void prework(){
    S["H"] = 1;
S["HE"] = 1;
S["LI"] = 1;
S["BE"] = 1;
S["B"] = 1;
S["C"] = 1;
S["N"] = 1;
S["O"] = 1;
S["F"] = 1;
S["NE"] = 1;
S["NA"] = 1;
S["MG"] = 1;
S["AL"] = 1;
S["SI"] = 1;
S["P"] = 1;
S["S"] = 1;
S["CL"] = 1;
S["AR"] = 1;
S["K"] = 1;
S["CA"] = 1;
S["SC"] = 1;
S["TI"] = 1;
S["V"] = 1;
S["CR"] = 1;
S["MN"] = 1;
S["FE"] = 1;
S["CO"] = 1;
S["NI"] = 1;
S["CU"] = 1;
S["ZN"] = 1;
S["GA"] = 1;
S["GE"] = 1;
S["AS"] = 1;
S["SE"] = 1;
S["BR"] = 1;
S["KR"] = 1;
S["RB"] = 1;
S["SR"] = 1;
S["Y"] = 1;
S["ZR"] = 1;
S["NB"] = 1;
S["MO"] = 1;
S["TC"] = 1;
S["RU"] = 1;
S["RH"] = 1;
S["PD"] = 1;
S["AG"] = 1;
S["CD"] = 1;
S["IN"] = 1;
S["SN"] = 1;
S["SB"] = 1;
S["TE"] = 1;
S["I"] = 1;
S["XE"] = 1;
S["CS"] = 1;
S["BA"] = 1;
S["LA"] = 1;
S["CE"] = 1;
S["PR"] = 1;
S["ND"] = 1;
S["PM"] = 1;
S["SM"] = 1;
S["EU"] = 1;
S["GD"] = 1;
S["TB"] = 1;
S["DY"] = 1;
S["HO"] = 1;
S["ER"] = 1;
S["TM"] = 1;
S["YB"] = 1;
S["LU"] = 1;
S["HF"] = 1;
S["TA"] = 1;
S["W"] = 1;
S["RE"] = 1;
S["OS"] = 1;
S["IR"] = 1;
S["PT"] = 1;
S["AU"] = 1;
S["HG"] = 1;
S["TL"] = 1;
S["PB"] = 1;
S["BI"] = 1;
S["PO"] = 1;
S["AT"] = 1;
S["RN"] = 1;
S["FR"] = 1;
S["RA"] = 1;
S["AC"] = 1;
S["TH"] = 1;
S["PA"] = 1;
S["U"] = 1;
S["NP"] = 1;
S["PU"] = 1;
S["AM"] = 1;
S["CM"] = 1;
S["BK"] = 1;
S["CF"] = 1;
S["ES"] = 1;
S["FM"] = 1;
S["MD"] = 1;
S["NO"] = 1;
S["LR"] = 1;
S["RF"] = 1;
S["DB"] = 1;
S["SG"] = 1;
S["BH"] = 1;
S["HS"] = 1;
S["MT"] = 1;
S["DS"] = 1;
S["RG"] = 1;
S["CN"] = 1;
S["NH"] = 1;
S["FL"] = 1;
S["MC"] = 1;
S["LV"] = 1;
S["TS"] = 1;
S["OG"] = 1;
}
int f[233];
int main(){
/*    FOR(i,1,118){
        char str[22];scanf("%s",str+1);
        int len = strlen(str+1);FOR(i,1,len) if('a' <= str[i] && str[i] <= 'z') str[i] = 'A'+str[i]-'a';
        printf("S[\"%s\"] = 1;\n",str);
    }*/
    prework();
    std::string str,now;
    std::cin >> str;
    int n = str.length();
    f[0] = S[str.substr(0,1)];
    f[1] |= S[str.substr(0,2)];
    f[1] |= (S[str.substr(0,1)]&S[str.substr(1,1)]);
    FOR(i,2,n-1){
        if(f[i-1]){
            f[i] |= S[str.substr(i,1)];
        }
        if(f[i-2]){
            f[i] |= S[str.substr(i-1,2)];
        }
    }
//    DEBUG(f[2]);
    puts(f[n-1]?"YES":"NO");
    return 0;
}