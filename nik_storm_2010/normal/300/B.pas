var
    g:array[1..48,1..48] of longint; used,num,col:array[1..48] of longint; have:array[1..48] of boolean;
      ans:array[1..16,1..3] of longint; color,time,kol,ost,cur,a,b,n,m,i,j:longint;


procedure bubblesort;
var i,j,w:longint;
begin
  for i:=1 to time do
    for j:=i+1 to time do
    if num[i]>num[j] then
    begin
      w:=num[i]; num[i]:=num[j]; num[j]:=w;
      w:=col[i]; col[i]:=col[j]; col[j]:=w;
    end;
end;


procedure rec(nom:longint);
var i:longint;
begin
  used[nom]:=time; inc(kol);
  for i:=1 to n do if (g[nom,i]=1) and (used[i]=0) then rec(i);
end;


procedure find(tek:longint; var color:longint);
var i:longint;
begin
  color:=-1;
  for i:=time downto 1 do
    if (have[i]=false) and (num[i]<=tek) then
    begin
      color:=col[i]; have[i]:=true;
      break;
    end;
end;


begin

  readln(n,m);
  for i:=1 to m do
    begin
      readln(a,b);
      g[a,b]:=1; g[b,a]:=1;
    end;
  time:=0;
  for i:=1 to n do
    if used[i]=0 then
    begin
      inc(time); kol:=0; rec(i);
      num[time]:=kol; col[time]:=time;
    end;
  bubblesort;
  if num[time]>3 then begin writeln(-1); halt; end;
  for i:=1 to n div 3 do
    begin
      ost:=3;
      while ost<>0 do
        begin
          find(ost,color);
          if color=-1 then begin writeln(-1); halt; end else
          begin
            for j:=1 to n do
              if used[j]=color then
              begin
                ans[i,ost]:=j; dec(ost);
              end;
          end;
        end;
    end;
  for i:=1 to n div 3 do writeln(ans[i,1],' ',ans[i,2],' ',ans[i,3]);

end.