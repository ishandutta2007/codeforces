uses math;
 var
    a,b:array[1..1000,1..1000] of longint;
     n,m,i,x,y,tek,ans:longint;


begin

  readln(n,m);
   for i:=1 to m do
    begin
     readln(x,y);
      a[x,y]:=1;
     b[x,y]:=i;
    end;
  ans:=maxlongint;
  for x:=1 to n-2 do
   for y:=1 to n-2 do
    begin
     if (a[x,y]=1) and (a[x+1,y]=1) and (a[x+2,y]=1) and (a[x,y+1]=1)
      and (a[x+1,y+1]=1) and (a[x+2,y+1]=1) and (a[x,y+2]=1) and (a[x+1,y+2]=1)
       and (a[x+2,y+2]=1)

       then
        begin
         tek:=b[x,y]; tek:=max(tek,b[x,y+1]); tek:=max(tek,b[x,y+2]);
          tek:=max(tek,b[x+1,y]); tek:=max(tek,b[x+1,y+1]); tek:=max(tek,b[x+1,y+2]);
          tek:=max(tek,b[x+2,y]); tek:=max(tek,b[x+2,y+1]); tek:=max(tek,b[x+2,y+2]);
         if tek<ans then ans:=tek;
        end;
    end;
  if ans=maxlongint
    then writeln(-1)
  else writeln(ans);


end.