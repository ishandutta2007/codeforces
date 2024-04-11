var
  g : array[1..3000,0..3000] of longint;
   tpath,path,used : array[1..3000] of boolean;
    n,i,i1,i2,r,tek : longint;
     priz : boolean;



procedure findcircle(nom,pred:longint);
var i,j:longint;
 begin

  path[nom]:=true;
   for i:=1 to g[nom,0] do
    begin

     if (g[nom,i] = r) and (pred <> r)
      then
       begin

        priz:=true;
         tpath:=path;
         exit;

       end;

     if (path[g[nom,i]]=false)
      then
       begin

        findcircle(g[nom,i],nom);

       end;

    end;
  path[nom]:=false;

 end;



procedure rec(nom,sum:longint);
var i:longint;
 begin

  used[nom]:=true;
   if tpath[nom] = true then begin tek:=sum; exit; end;

  for i:=1 to g[nom,0] do
   if used[g[nom,i]] = false then rec(g[nom,i],sum+1);
  used[nom]:=false;

 end;



begin

  readln(n);
   for i:=1 to n do
    begin

     readln(i1,i2);
      inc(g[i1,0]); g[i1,g[i1,0]]:=i2;
       inc(g[i2,0]); g[i2,g[i2,0]]:=i1;

    end;

   for r:=1 to n do
    begin

     priz:=false;
      findcircle(r,MaxLongint);
       if priz = true then break;

    end;

  for i:=1 to n do
   begin

    tek:=0;
     fillchar(used,sizeof(used),false);
     rec(i,0);
    write(tek,' ');

   end;

end.