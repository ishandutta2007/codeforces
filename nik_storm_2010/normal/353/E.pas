uses
  math;
const
  ll=2000000;
var
  l,r,num:array[1..ll] of longint;
  used:array[1..ll] of boolean;
  n,i,k1,k2,x,cnt:longint;
  maybe:boolean;
  s:ansistring;

function prev(x:longint):longint;
begin
  if (x=1) then prev:=n else prev:=x-1;
end;

function next(x:longint):longint;
begin
  if (x=n) then next:=1 else next:=x+1;
end;

function dfs(x:longint):longint;
begin
  if (s[x]='1') then dfs:=1+dfs(prev(x)) else exit(0);
end;

function bfs(x:longint):longint;
begin
  if (s[x]='0') then bfs:=1+bfs(next(x)) else exit(0);
end;

function good(x:longint):boolean;
var
  i:longint;
begin
  i:=prev(x);
  if (s[i]='1') and (s[x]='0') then good:=true else good:=false;
end;

begin
  readln(s);
  n:=length(s);
  for i:=1 to n do if (good(i)) then
  begin
    x:=prev(i);
    inc(cnt);
    num[cnt]:=i;
    l[cnt]:=dfs(x);
    r[cnt]:=bfs(i);
  end;
  fillchar(used,sizeof(used),false);
  k1:=1;
  used[1]:=true;
  for i:=2 to cnt do
  begin
    maybe:=true;
    if (r[i-1]=1) then
    begin
      if (used[i-1]=false) then maybe:=false else
      begin
        if (l[i]>1) then begin maybe:=false; inc(k1); end;
      end;
    end
      else
    begin
      if (l[i]>1) then begin inc(k1); maybe:=false; end;
    end;
    if (maybe) then begin used[i]:=true; inc(k1); continue; end;
    if (cnt=i) and (used[1]) and (r[i]=1) then continue else inc(k1);
  end;
  fillchar(used,sizeof(used),false);
  k2:=1;
  for i:=2 to cnt do
  begin
    maybe:=true;
    if (r[i-1]=1) then
    begin
      if (used[i-1]=false) then maybe:=false else
      begin
        if (l[i]>1) then begin maybe:=false; inc(k2); end;
      end;
    end
      else
    begin
      if (l[i]>1) then begin inc(k2); maybe:=false; end;
    end;
    if (maybe) then begin used[i]:=true; inc(k2); continue; end;
    if (cnt=i) and (used[1]) and (r[i]=1) then continue else inc(k2);
  end;
  if (r[cnt]=1) and (used[cnt]=false) then else
  begin
    if (l[1]>1) then inc(k2);
  end;
  writeln(max(k1,k2));
end.