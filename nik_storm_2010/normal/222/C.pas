uses math;
var
    a:array[1..2,1..10000000] of longint; s:array[1..2,1..100000] of longint;
      pro:array[0..1000] of longint; n,m,i,j,c:longint;


function prost(tek:longint):boolean;
  var i,q:longint;
begin
  q:=round(sqrt(tek));
  for i:=2 to q do
    if tek mod i=0 then
      begin
        prost:=false;
        exit;
      end;
  prost:=true;
end;


procedure razlog(c,nom:longint);
  var i:longint;
begin
  i:=1;
  while pro[i]*pro[i]<=c do
    begin
      while c mod pro[i]=0 do
        begin
          inc(a[nom,pro[i]]);
          c:=c div pro[i];
        end;
      inc(i); if i=pro[0]+1 then break;
    end;
  if c<>1 then inc(a[nom,c]);
end;


function cut(tek,nom:longint):longint;
  var i,ans:longint;
begin
  i:=1; ans:=tek;
  while pro[i]*pro[i]<=tek do
    begin
      if a[nom,pro[i]]=0 then
        begin
          while tek mod pro[i]=0 do tek:=tek div pro[i];
        end
          else
        begin
          while (a[nom,pro[i]]>0) and (tek mod pro[i]=0) do
            begin
              ans:=ans div pro[i]; tek:=tek div pro[i];
              dec(a[nom,pro[i]]);
            end;
          while tek mod pro[i]=0 do tek:=tek div pro[i];
        end;
      inc(i);
    end;
  if (tek<>1) and (a[nom,tek]>0) then
    begin
      dec(a[nom,tek]); ans:=ans div tek;
    end;
  cut:=ans;
end;


begin

  for i:=2 to 3250 do if prost(i) then begin inc(pro[0]); pro[pro[0]]:=i; end;

  readln(n,m);
  for i:=1 to n do
    begin
      read(s[1,i]); razlog(s[1,i],1);
    end; readln;
  for i:=1 to m do
    begin
      read(s[2,i]); razlog(s[2,i],2);
    end;
  for i:=1 to 10000000 do
    begin
      c:=min(a[1,i],a[2,i]);
      a[1,i]:=c; a[2,i]:=c;
    end;

  writeln(n,' ',m);
  for i:=1 to n do
    begin
      s[1,i]:=cut(s[1,i],1);
      write(s[1,i],' ');
    end; writeln;
  for i:=1 to m do
    begin
      s[2,i]:=cut(s[2,i],2);
      write(s[2,i],' ');
    end;

end.