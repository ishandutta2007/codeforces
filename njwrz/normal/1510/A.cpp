//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
struct matrix{
    int n,m,st;
    vector<string> g;
    matrix(string s){
        n=3;m=s.size()+4;st=1;
        FOR(i,0,2){
        	string ts;
        	if(i==st){
        		ts="+ "+s+" +";
			}else{
				ts="+-";
				for(auto u:s)ts+='-';
				ts+="-+";
			}
			g.PB(ts);
		}
    }
    void merge1(vector<matrix> v){
        n=-1;m=0;st=v.front().st;
        for(matrix a:v){
            n+=a.n+1;
            m=max(m,a.m+6);
        }
        g.resize(n,string(m,' '));n=0;
        for(matrix a:v){
            g[n+a.st][0]=g[n+a.st][m-1]='+';
            g[n+a.st][1]=g[n+a.st][m-3]='-';
            g[n+a.st][2]=g[n+a.st][m-2]='>';
            rep(i,0,a.n)rep(j,0,a.m){
                g[i+n][j+3]=a.g[i][j];
            }
            rep(i,a.m+3,m-3)g[a.st+n][i]='-';
            n+=a.n+1;
        }
        n--;
        bool f=0;
        for(int i=n-1;i>st;i--){
            f|=g[i][0]=='+';
            if(g[i][0]==' '&&f)g[i][0]=g[i][m-1]='|';
        }
    }
    void merge2(vector<matrix> v){
        n=0;m=-2;st=0;
        for(matrix &a:v){
            m+=a.m+2;
            st=max(st,a.st);
            n=max(n,a.n-a.st);
        }
        n+=st;
        g.resize(n,string(m,' '));
        int p=0;
        for(matrix &a:v){
            rep(i,0,a.n)rep(j,0,a.m){
                g[i+st-a.st][j+p]=a.g[i][j];
            }
            p+=a.m+2;
            if(p<m){
                g[st][p-1]='>';
                g[st][p-2]='-';
            }
        }
    }
    void solve1(matrix a){
        n=a.n+2;
        m=a.m+6;
        st=a.st;
        g.resize(n,string(m,' '));
        g[st][0]='+';g[st][1]='-';g[st][2]='>';
        g[st][m-3]='-';g[st][m-2]='>';g[st][m-1]='+';
        rep(i,0,a.n)rep(j,0,a.m)g[i][j+3]=a.g[i][j];
        rep(i,st+1,n-1)g[i][0]=g[i][m-1]='|';
        rep(i,0,m-1)g[n-1][i]='-';
        g[n-1][0]=g[n-1][m-1]='+';
        g[n-1][1]='<';
    }
    void solve2(matrix a){
        n=a.n+3;
        m=a.m+6;
        st=a.st+3;
        g.resize(n,string(m,' '));
        g[st][0]=g[st][m-1]='+';
        g[st][1]=g[st][m-3]='-';
        g[st][2]=g[st][m-2]='>';
        rep(i,0,a.n)rep(j,0,a.m)g[i+3][j+3]=a.g[i][j];
        rep(i,2,st)g[i][0]=g[i][m-1]='|';
        rep(i,1,m-2)g[1][i]='-';
        g[1][0]=g[1][m-1]='+';
        g[1][m-2]='>';
        st=1;
    }
    void solve3(matrix a){
        n=a.n+5;
        m=a.m+6;
        st=a.st+3;
        g.resize(n,string(m,' '));
        g[st][0]=g[st][m-1]='+';
        g[st][1]=g[st][m-3]='-';
        g[st][2]=g[st][m-2]='>';
        rep(i,0,a.n)rep(j,0,a.m)g[i+3][j+3]=a.g[i][j];
        rep(i,2,st)g[i][0]=g[i][m-1]='|';
        rep(i,1,m-2)g[1][i]='-';
        g[1][0]=g[1][m-1]='+';
        g[1][m-2]='>';
        rep(i,st+1,n-1)g[i][0]=g[i][m-1]='|';
        rep(i,2,m-1)g[n-1][i]='-';
        g[n-1][0]=g[n-1][m-1]='+';
        g[n-1][1]='<';
        st=1;
    }
    matrix(matrix a,char c){
        if(c=='+'){
            solve1(a);
        }else if(c=='?'){
            solve2(a);
        }else{
            solve3(a);
        }
    }
    matrix(vector<matrix> a,char c){
        if(c=='h'){
            merge1(a);
        }else{
            merge2(a);
        }
    }
};
bool check(char c){
	RE c=='*'||c=='?'||c=='+';
}
matrix expr(string s);
matrix atom(string s){
	if(check(s[s.size()-1])){
		RE matrix(atom(s.substr(0,s.size()-1)),s[s.size()-1]);
	}else if(s[0]=='('&&s[s.size()-1]==')'){
		RE expr(s.substr(1,s.size()-2));
	}else RE matrix(s);
}
matrix term(string s){
	V<matrix> re;
	rep(i,0,s.size()){
		if(s[i]=='('){
			int j=i;
			int t=1;
			while(t){
				j++;
				t+=s[j]=='(';
				t-=s[j]==')';
			}
			while(j+1<s.size()&&check(s[j+1]))j++;
			re.PB(atom(s.substr(i,j-i+1)));
			i=j;
		}else {
			if(s[i+1]>='A'&&s[i+1]<='Z'){
				int j=i;
				while(j+1<s.size()&&s[j+1]>='A'&&s[j+1]<='Z')j++;
				if(j==s.size()-1||s[j+1]=='(')j++;
				re.PB(matrix(s.substr(i,j-i)));
				i=j-1;
			}else{
				int j=i;
				while(j+1<s.size()&&check(s[j+1]))j++;
				re.PB(atom(s.substr(i,j-i+1)));
				i=j;
			}
		}
	}
	RE matrix(re,'l');
}
matrix expr(string s){
	int t=0,lst=0;
	V<matrix> re;
	rep(i,0,s.size()){
		t+=s[i]=='(';
		t-=s[i]==')';
		if(!t&&s[i]=='|'){
			re.PB(term(s.substr(lst,i-lst)));
			lst=i+1;
		}
	}
	re.PB(term(s.substr(lst,s.size()-lst)));
	if(re.size()==1){
		RE re.back();
	}else RE matrix(re,'h');
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	matrix ans=expr(s);
	cout<<ans.n<<' '<<ans.m+6<<'\n';
	rep(i,0,ans.g.size()){
		if(i==ans.st){
			cout<<"S->";
		}else cout<<"   ";
		cout<<ans.g[i];
		if(i==ans.st){
			cout<<"->F";
		}else cout<<"   ";
		cout<<'\n';
	}
	RE 0;
}