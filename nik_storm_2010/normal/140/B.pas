var
 a : array[1..300,1..300] of longint;
  b : array[1..300] of longint;
   used : array[1..300] of boolean;
    n,i,j,nom : longint;


procedure findbest(nom:longint; var ans:longint);
var i,j,tek,num:longint; best:longint;
 begin
  tek:=maxlongint;
   for i:=1 to n do
    begin
     used[i]:=true; best:=maxlongint;
      for j:=1 to n do
       if (used[b[j]]=true) and (b[j]<>nom)
        then
         begin
          best:=b[j];
          break;
         end;
     num:=maxlongint;
      if best <> maxlongint
       then
        begin
         for j:=1 to n do
          if a[nom,j]=best
           then
            begin
             num:=j;
             break;
            end;
        end;
     if num<tek then begin tek:=num; ans:=best; end;
    end;
 end;


begin

  readln(n);
   for i:=1 to n do
    begin
     for j:=1 to n do read(a[i,j]);
     readln;
    end;
  for i:=1 to n do read(b[i]);

  for i:=1 to n do
   begin
    fillchar(used,sizeof(used),false);
     findbest(i,nom);
    write(nom,' ');
   end;

end.