uses math; type ee=record t,n:longint; end; const lim=200000;
var
  a,g:array[1..lim] of array of int64; e:array[1..lim] of ee; good:boolean; i,j:longint;
  name,leng,cnt,mi,ma,h,s,ll,met,p:array[1..lim] of int64; size,big,m,n,cur,k:int64;


procedure addedge(a,b:longint);
begin
  inc(k);
  e[k].t:=b; e[k].n:=s[a]; s[a]:=k;
end;


procedure swap(i,j:longint);
var w:longint;
begin
  p[h[i]]:=j; p[h[j]]:=i;
  w:=h[i]; h[i]:=h[j]; h[j]:=w;
end;


procedure modify(x,y:longint);
var i:longint;
begin
  i:=p[x]; mi[x]:=y;
  while (i>1) and (mi[h[i]]<mi[h[i div 2]]) do
  begin
    swap(i,i div 2); i:=i div 2;
  end;
end;


procedure out(var x,y:int64);
var i,no:longint;
begin
  x:=h[1]; y:=mi[h[1]]; swap(1,size); dec(size);
  i:=1;
  while (i*2<=size) do
  begin
    no:=i*2;
    if (i*2+1<=size) and (mi[h[i*2]]>mi[h[i*2+1]]) then no:=i*2+1;
    if (mi[h[i]]>mi[h[no]]) then begin swap(i,no); i:=no; end else break;
  end;
end;


procedure findmin;
var res,num,x:int64; i,j:longint;
begin
  size:=n;
  for i:=1 to n do begin h[i]:=i; p[i]:=i; mi[i]:=maxlongint; ma[i]:=-1; end;
  for i:=1 to m do if cnt[i]=0 then
  begin
    if leng[i]<mi[name[i]] then modify(name[i],leng[i]);
  end;
  while size<>0 do
  begin
    out(num,x); if x=maxlongint then exit;
    i:=s[num];
    while i<>0 do
    begin
      dec(cnt[e[i].t]);
      if cnt[e[i].t]=0 then
      begin
        res:=0;
        for j:=1 to leng[e[i].t]  do
          if g[e[i].t,j]=-1 then inc(res) else inc(res,mi[g[e[i].t,j]]);
        res:=min(res,big);
        if res<mi[name[e[i].t]] then modify(name[e[i].t],res);
      end;
      i:=e[i].n;
    end;
  end;
end;


procedure dfs(nom:longint);
var i,j,q:longint; res:int64;
begin
  if ma[nom]<>-1 then exit;
  met[nom]:=1;
  for i:=1 to ll[nom] do
  begin
    res:=0;
    for j:=1 to leng[a[nom,i]] do
    begin
      q:=g[a[nom,i],j];
      if q=-1 then inc(res) else
      begin
        if met[q]<>1 then dfs(q);
        if (met[q]=1) or (ma[q]=-2) then begin ma[nom]:=-2; met[nom]:=2; exit; end;
        res:=res+ma[q];
      end;
      res:=min(res,big);
    end;
    ma[nom]:=max(res,ma[nom]);
  end;
  met[nom]:=2;
end;


begin

  readln(m,n); big:=314000000;
  for i:=1 to m do
  begin
    read(name[i],leng[i]); setlength(g[i],leng[i]+1);
    for j:=1 to leng[i] do
    begin
      read(g[i,j]);
      if g[i,j]<>-1 then begin inc(cnt[i]); addedge(g[i,j],i); end;
    end;
    readln;
  end;
  findmin;
  for i:=1 to m do
  begin
    good:=true;
    for j:=1 to leng[i] do if (g[i,j]<>-1) and (mi[g[i,j]]=maxlongint) then begin good:=false; break; end;
    if good=false then continue;
    inc(ll[name[i]]); setlength(a[name[i]],ll[name[i]]+1);
    a[name[i],ll[name[i]]]:=i;
  end;
  for i:=1 to n do if mi[i]<>maxlongint then dfs(i);
  for i:=1 to n do
  begin
    if mi[i]=maxlongint then write(-1,' ') else write(mi[i],' ');
    writeln(ma[i]);
  end;

end.