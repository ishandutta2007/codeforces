const ext = 1000000007;
 var old1,new1,old2,new2,old3,new3,old4,new4 : longword;
    n,i : longint;


begin

  readln(n);
   old1:=1;
  for i:=1 to n do
   begin

     new1:=(old2+old3+old4) mod ext;
      new2:=(old1+old3+old4) mod ext;
      new3:=(old1+old2+old4) mod ext;
     new4:=(old1+old2+old3) mod ext;

     old1:=new1; old2:=new2; old3:=new3; old4:=new4;

   end;
  writeln(old1);

end.