const mas:array[1..2,1..4] of longint = ((+1,-1,0,0),(0,0,+1,-1));
var
    a:array[0..51,0..51] of char; q:array[1..4,1..10000] of longint;
      used:array[0..51,0..51] of boolean; st,en,n,m,i,j,x,y:longint;


procedure addq(i,j,dir,nom:longint);
begin
  q[1,en]:=i; q[2,en]:=j; q[3,en]:=dir; q[4,en]:=nom;
  inc(en);
end;


procedure outq(var i,j,dir,nom:longint);
begin
  i:=q[1,st]; j:=q[2,st]; dir:=q[3,st]; nom:=q[4,st];
  inc(st);
end;


procedure bfs(i,j:longint);
var dir,cnt,nom,x,y:longint;
begin
  fillchar(used,sizeof(used),false); st:=1; en:=1; used[i,j]:=true; addq(i,j,0,2);
  while st<>en do
    begin
      outq(x,y,dir,cnt);
      for nom:=1 to 4 do
        begin
          i:=x+mas[1,nom]; j:=y+mas[2,nom];
          if (a[i,j]<>'B') then continue;
          if nom=dir then
            begin
              used[i,j]:=true; addq(i,j,dir,cnt);
            end
              else
            begin
              if cnt<>0 then begin used[i,j]:=true; addq(i,j,nom,cnt-1); end;
            end;
        end;
    end;
end;


begin

  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[i,j]);
      readln;
    end;
  for i:=1 to n do
    for j:=1 to m do
    if a[i,j]='B' then
    begin
      bfs(i,j);
      for x:=1 to n do
        for y:=1 to m do
        if (a[x,y]='B') and (used[x,y]=false) then
          begin
            writeln('NO');
            halt;
          end;
    end;
  writeln('YES');

end.