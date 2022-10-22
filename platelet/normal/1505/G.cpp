#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	int a, b, c, d, e, n;
	cin >> n;
	while(n--) {
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	if(a == 1 && b == 0 && c == 0 && d == 1 && e == 0) printf("a");
	else if(a == 1&&b==1&&c==0&&d==2&&e==0)printf("b");
	else if(a == 2&&b==0&&c==0&&d==1&&e==1)printf("c");
	else if(a == 2&&b==1&&c==0&&d==1&&e==2)printf("d");
	else if(a == 1&&b==1&&c==0&&d==1&&e==1)printf("e");
	else if(a == 2&&b==1&&c==0&&d==2&&e==1)printf("f");
	else if(a == 2&&b==2&&c==0&&d==2&&e==2)printf("g");
	else if(a == 1&&b==2&&c==0&&d==2&&e==1)printf("h");
	else if(a == 1&&b==1&&c==0&&d==1&&e==1)printf("i");
	else if(a == 1&&b==2&&c==0&&d==1&&e==2)printf("j");
	else if(a == 1&&b==0&&c==1&&d==2&&e==0)printf("k");
	else if(a == 1&&b==1&&c==1&&d==3&&e==0)printf("l");
	else if(a == 2&&b==0&&c==1&&d==2&&e==1)printf("m");
	else if(a == 2&&b==1&&c==1&&d==2&&e==2)printf("n");
	else if(a == 1&&b==1&&c==1&&d==2&&e==1)printf("o");
	else if(a == 2&&b==1&&c==1&&d==3&&e==1)printf("p");
	else if(a == 2&&b==2&&c==1&&d==3&&e==2)printf("q");
	else if(a == 1&&b==2&&c==1&&d==3&&e==1)printf("r");
	else if(a == 1&&b==1&&c==1&&d==2&&e==1)printf("s");
	else if(a == 1&&b==2&&c==1&&d==2&&e==2)printf("t");
	else if(a == 1&&b==0&&c==2&&d==2&&e==1)printf("u");
	else if(a == 1&&b==1&&c==2&&d==3&&e==1)printf("v");
	else if(a == 1&&b==2&&c==1&&d==1&&e==3)printf("w");
	else if(a == 2&&b==0&&c==2&&d==2&&e==2)printf("x");
	else if(a == 2&&b==1&&c==2&&d==2&&e==3)printf("y");
	else if(a == 1&&b==1&&c==2&&d==2&&e==2)printf("z");
}
	return 0;
}