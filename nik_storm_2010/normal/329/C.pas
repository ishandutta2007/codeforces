const size=200100;
type edges=record t,n:longint; end;
var
  g,h:array[1..7,1..7] of byte; mas:array[1..size] of array of longint;  used:array[1..size] of boolean;
  s,d,ans,ll:array[1..size] of longint; n,m,max,i,j,a,b,nom,cnt,it:longint; e:array[1..size] of edges;
  gg:array[1..2,1..21] of longint; top:array[1..21] of longint;


procedure addedge(a,b,nom:longint);
begin
  e[nom].t:=b; e[nom].n:=s[a];
  s[a]:=nom;
end;


procedure dfs(nom:longint);
var i:longint;
begin
  used[nom]:=true; inc(cnt); d[cnt]:=nom; i:=s[nom];
  while i<>0 do
  begin
    if used[e[i].t]=false then dfs(e[i].t);
    i:=e[i].n;
  end;
end;


procedure gen(nom,kk:longint);
var i:longint;
begin
  if kk=m then
  begin
    for i:=1 to cnt do if top[i]=1 then writeln(gg[1,i],' ',gg[2,i]);
    halt;
  end;
  if nom=cnt+1 then exit;
  if (g[gg[1,nom],gg[2,nom]]=0) and (ll[gg[1,nom]]<>2) and (ll[gg[2,nom]]<>2) then
  begin
    top[nom]:=1; inc(ll[gg[1,nom]]); inc(ll[gg[2,nom]]);
    gen(nom+1,kk+1);
    top[nom]:=0; dec(ll[gg[1,nom]]); dec(ll[gg[2,nom]]);
  end;
  gen(nom+1,kk);
end;


begin

  readln(n,m);
  if n<=7 then
  begin
    for i:=1 to m do
    begin
      readln(a,b);
      g[a,b]:=1; g[b,a]:=1;
    end;
    cnt:=0;
    for i:=1 to n do
      for j:=i+1 to n do
      begin inc(cnt); gg[1,cnt]:=i; gg[2,cnt]:=j; end;
    gen(1,0);
    writeln(-1);
  end
    else
  begin
    for i:=1 to m do
    begin
      readln(a,b); inc(ll[a]); inc(ll[b]);
      addedge(a,b,i*2-1); addedge(b,a,i*2);
    end;
    max:=0;
    for i:=1 to n do if (used[i]=false) and (ll[i]=1) then
    begin
      inc(it); cnt:=0; dfs(i);
      setlength(mas[it],cnt+1);
      mas[it,0]:=0;
      for j:=1 to cnt do if j mod 2=1 then begin inc(mas[it,0]); mas[it,mas[it,0]]:=d[j]; end;
      for j:=1 to cnt do if j mod 2=0 then begin inc(mas[it,0]); mas[it,mas[it,0]]:=d[j]; end;
      if cnt mod 2=0 then
      begin
        a:=mas[it,1]; mas[it,1]:=mas[it,2]; mas[it,2]:=a;
      end;
      if cnt>max then begin max:=cnt; nom:=it; end;
    end;
    for i:=1 to n do if used[i]=false then
    begin
      inc(it); cnt:=0; dfs(i);
      setlength(mas[it],cnt+1);
      mas[it,0]:=0;
      for j:=1 to cnt do if j mod 2=1 then begin inc(mas[it,0]); mas[it,mas[it,0]]:=d[j]; end;
      for j:=1 to cnt do if j mod 2=0 then begin inc(mas[it,0]); mas[it,mas[it,0]]:=d[j]; end;
      if cnt mod 2=0 then
      begin
        a:=mas[it,1]; mas[it,1]:=mas[it,2]; mas[it,2]:=a;
      end;
      if cnt>max then begin max:=cnt; nom:=it; end;
    end;
    fillchar(s,sizeof(s),0); fillchar(e,sizeof(e),0);
    cnt:=1; a:=1;
    for i:=1 to it do
    if i<>nom then
    begin
      for j:=1 to mas[i,0] do
      begin
        addedge(a,mas[i,j],cnt); inc(cnt); inc(a);
        if a>max then a:=1;
      end;
    end;
    cnt:=1;
    for i:=1 to max do
    begin
      ans[cnt]:=mas[nom,i]; j:=s[i]; inc(cnt);
      while j<>0 do
      begin
        ans[cnt]:=e[j].t; inc(cnt);
        j:=e[j].n;
      end;
    end;
    ans[n+1]:=ans[1];
    for i:=1 to m do writeln(ans[i],' ',ans[i+1]);
  end;

end.