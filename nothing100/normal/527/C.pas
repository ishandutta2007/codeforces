var
  n,m,l:longint;
  ma:array [0..1] of int64;
  ans:array [0..200000] of int64;
  ques,f,a:array [0..200000,0..1] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
function get(x,y:longint):longint;
var
  o:longint;
begin
  if f[x,y]=x then exit(x)
  else
  begin
    o:=get(f[x,y],y);
    f[x,y]:=o;
    exit(o);
  end;
end;
procedure init;
var
  i,j,o,p:longint;
  ch:char;
begin
  readln(n,m,l);
  for i:=1 to l do
  begin
    readln(ch,ques[i,1]);
    if ch='H' then ques[i,0]:=1
    else ques[i,0]:=0;
    f[ques[i,1],ques[i,0]]:=ques[i,1];
  end;
  for i:=0 to n-1 do
  begin
    if f[i,0]=i then o:=i;
    inc(a[o,0]); ma[0]:=max(ma[0],a[o,0]); f[i,0]:=o;
  end;
  for i:=0 to m-1 do
  begin
    if f[i,1]=i then o:=i;
    inc(a[o,1]); ma[1]:=max(ma[1],a[o,1]); f[i,1]:=o;
  end;
  for i:=l downto 1 do
  begin
    ans[i]:=ma[0]*ma[1];
    o:=get(ques[i,1],ques[i,0]);
    p:=get(ques[i,1]-1,ques[i,0]);
    f[o,ques[i,0]]:=p;
    a[p,ques[i,0]]:=a[o,ques[i,0]]+a[p,ques[i,0]];
    ma[ques[i,0]]:=max(ma[ques[i,0]],a[p,ques[i,0]]);
  end;
  for i:=1 to l do writeln(ans[i]);
end;
begin
  init;
end.