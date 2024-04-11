#include <bits/stdc++.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
 
#define mp make_pair
#define pb push_back
#define INF 1000000000
 
typedef long long ll;
typedef pair<int,int> pii;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
 
int main()
{
 ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i,k,sum,x=0;
	cin>>n>>k;
	string s;
	cin>>s;
	for (i=0;i<n;i++)
	{
		if (s[i]=='.') x=1;
		if ((s[i]-48>=5) and(x)) break;
	}
	if (i==n) {cout<<s; return 0;}
	else
	{
		for (x=0;x<k;x++) { if (s[i-x]=='.') {i--; for (int j=i-x;j>=0;j--) 
	if (s[j]=='9') if (j==0) {cout<<'1'; s[j]='0'; break;} else s[j]='0'; else {s[j]++; break;} 
	for (int j=0; j<=i-x;j++) cout<<s[j]; return 0;
		
	} if (s[i-x]-48<4) break;  }
	}
	if (s[i-x]=='.') {i--; for (int j=i-x;j>=0;j--) 
	if (s[j]=='9') if (j==0) {cout<<'1'; s[j]='0'; break;} else s[j]='0'; else {s[j]++; break;} 
	for (int j=0; j<=i-x;j++) cout<<s[j]; return 0;
		
	}
	for (int j=0;j<i-x;j++) cout<<s[j];
	char c=s[i-x]+1;
	cout<<c;
}
/*
I think this is the right time of showing the way of team selection in Japan, so I spare time for writing a blog, instead of preparing for Distributed Code Jam finals.

Compared to other countries, Japanese selection rules are very simple. Perhaps this is the simplest rule among the countries getting gold medal almost every year.

There are 3 rounds to go to IOI. Each round is independent so even if you don't do well in the previous round, you wouldn't have disadvantages for the next round (as long as you are qualified).

1. JOI Qualification Round (JOI )
The number of participants is a bit larger than 1,000. There are 6 tasks and contest duration is 3 hours. Judging from the past years' problems, the first task is really easy (like "I have 10 integers, and I'll give you 9 of my integers and the sum of all my integers. Can you guess the remaining integer?"), and about 5 students can solve the last task. This round is held online, and it seems AtCoder system will be used for the first time this year. If you have participated in Selection Camp before, you are automatically qualified to the Final Round. Otherwise, about 60 students with highest score advance to the next round, and there are other qualified students that even I don't know how are selected ( BLACK BOX :( ).

You can find and solve past problems on Aizu Online Judge. Some problems are translated in English and some can be read through Google Translate.

2. JOI Final Round (JOI )
This is the national championship. The top 3 members are awarded medals and laptops. The number of participants is 70 to 80, and the contest is held in Tokyo or Tsukuba (the next IOI's place). You don't have to pay for your travel fee and staying cost, and the contest takes 2 days (including practice session and party). That's why I started to participate in JOI when I was 8th grade.

Usually, the contest has 5 problems and 4 hours, and cutoff line is between 2 full-solutions and 3 full-solutions (I think). Sometimes the last problem of this round is the hardest problem of the year.

You can also find and solve past problems on Aizu Online Judge.

3. JOI Spring Camp (JOI )
The most important round for participants. The national team is selected by the result of this camp. Around 20 students with highest score in the Final Round can participate in this camp.

Usually, the camp contains 4 competition days (the camp itself is 7 days long, including practice round, lectures, and awarding ceremony of the Final Round). In each day, there's an IOI-styled contest with 3 or 4 problems and 5 hours. Despite only batch-style problems are used in previous two rounds, various kinds of problems are seen in this camp, including output-only, communication task, encode-decode task, etc.

The problems used in the camp are known as "toughest yet most interesting problems" in Japan. I agree with the "toughest" for this year, because even yutaka1999 couldn't solve more than a half of the problems. "Most interesting"? I can't judge it since there are so many interesting contests in Japan, thanks to AtCoder.

The top 4 students are selected for Japanese national team of IOI. Oh, what a simple selecting method.

You can find past problems here (Japanese) and judge is on AtCoder (example, by changing the URL you can submit to past problems). Luckily, this year's problems are translated in English, so you can practice without the help of Google Translate (awoo).

4. JOI Open Contest
Practice contest for IOI, usually held in June or July. Usually 3 problems in 5 hours.

This is not related to national team selection, so students can be relaxed to take part in the contest. the problem statement is provided in both Japanese and English. You can find further explanation on Codeforces (maybe joisino posts about this contest every year).

5. Conclusion
Practicing with other country's OI problems seems very helpful, but they are often written only in their mother languages. Translating problems is a demanding work and nobody wants to do without payment. That means learning a new language for competitive programming practice makes sense (really?).
*/