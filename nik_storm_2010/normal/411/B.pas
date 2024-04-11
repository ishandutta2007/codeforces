const
  l=300;
var
  go:array[0..l,0..l] of longint;
  used:array[0..l] of boolean;
  cnt,ans:array[0..l] of longint;
  n,m,k,i,j:longint;

procedure up(x,y:longint);
begin
  if (ans[x]=0) then ans[x]:=y;
end;

begin
  readln(n,m,k);
  for i:=1 to n do for j:=1 to m do
  begin
    read(go[i,j]);
    if (j=m) then readln;
  end;
  fillchar(used,sizeof(used),false);
  for i:=1 to m do
  begin
    fillchar(cnt,sizeof(cnt),0);
    for j:=1 to n do if (go[j,i]<>0) and (used[go[j,i]]) then up(j,i);
    for j:=1 to n do if (go[j,i]<>0) and (used[go[j,i]]=false) and (ans[j]=0) then inc(cnt[go[j,i]]);
    for j:=1 to n do if (go[j,i]<>0) and (cnt[go[j,i]]<>1) and (ans[j]=0) then
    begin
      up(j,i);
      used[go[j,i]]:=true;
    end;
  end;
  for i:=1 to n do writeln(ans[i]);
end.