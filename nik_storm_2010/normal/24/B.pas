Var
    nam: array[1..101] of shortstring;
     kol: array[1..101,0..100] of longint;
      t,n,i,j,y,nom,kolnam: longint;
       s: string;


procedure increase(nom,position:longint);
 begin
  case position of
   1: inc(kol[nom,0],25);
    2: inc(kol[nom,0],18);
     3: inc(kol[nom,0],15);
      4: inc(kol[nom,0],12);
       5: inc(kol[nom,0],10);
        6: inc(kol[nom,0],8);
         7: inc(kol[nom,0],6);
          8: inc(kol[nom,0],4);
           9: inc(kol[nom,0],2);
            10: inc(kol[nom,0],1);
  end;
 end;


function prov(n1,n2,nom:longint):boolean;
var i:longint;
 begin
  if nom=1
   then
    begin
     if kol[n1,0] > kol[n2,0] then exit(false);
      if kol[n1,0] < kol[n2,0] then exit(true);
       for i:=1 to 100 do
        begin
         if kol[n1,i] > kol[n2,i] then exit(false);
          if kol[n1,i] < kol[n2,i] then exit(true);
        end;
    end
   else
    begin
     if kol[n1,1] > kol[n2,1] then exit(false);
      if kol[n1,1] < kol[n2,1] then exit(true);
     if kol[n1,0] > kol[n2,0] then exit(false);
      if kol[n1,0] < kol[n2,0] then exit(true);
       for i:=2 to 100 do
        begin
         if kol[n1,i] > kol[n2,i] then exit(false);
          if kol[n1,i] < kol[n2,i] then exit(true);
        end;
    end;
  exit(false);
 end;


procedure qsort(nom,l,r:longint);
var i,j,d,w:longint;
 begin
  i:=l;
   j:=r;
    d:=(i+j) div 2;
     while i<=j do
      begin
       while prov(i,d,nom)=true do inc(i);
        while prov(d,j,nom)=true do dec(j);
         if i<=j
          then
           begin
            for w:=0 to 100 do kol[101,w]:=kol[i,w];
             for w:=0 to 100 do kol[i,w]:=kol[j,w];
              for w:=0 to 100 do kol[j,w]:=kol[101,w];
               nam[101]:=nam[i];
                nam[i]:=nam[j];
                 nam[j]:=nam[101];
                  inc(i);
                   dec(j);
           end;
      end;
  if i<r then qsort(nom,i,r);
   if l<j then qsort(nom,l,j);
 end;


Begin

  readln(t);
   kolnam:=0;
    for i:=1 to t do
     begin
      readln(n);
       for j:=1 to n do
        begin
         readln(s);
          nom:=-1;
           for y:=1 to kolnam do
            if s=nam[y]
             then
              begin
               nom:=y;
                break;
              end;
         if nom=-1
          then
           begin
            inc(kolnam);
             nam[kolnam]:=s;
              increase(kolnam,j);
               inc(kol[kolnam,j]);
           end
          else
           begin
            increase(nom,j);
             inc(kol[nom,j]);
           end;
        end;
    end;

   qsort(1,1,kolnam);
    writeln(nam[kolnam]);
   qsort(2,1,kolnam);
    writeln(nam[kolnam]);

End.